import argparse
import collections
import pprint
from pwn import *
from pycparser import *
from pycparser import parse_file


p = argparse.ArgumentParser(description='''
Parse a header file into Python to extract the function signatures
''')

p.add_argument('file')
p.add_argument('-v','--verbose',action='store_true')

args = p.parse_args()

ast = parse_file(args.file)


def extractTypeAndName(n, defaultName=None):
    if isinstance(n, c_ast.EllipsisParam):
        return ('int', 0, 'vararg')

    t = n.type
    d = 0

    while isinstance(t, c_ast.PtrDecl) or isinstance(t, c_ast.ArrayDecl):
        d += 1
        children  = dict(t.children())
        t = children['type']

    if isinstance(t, c_ast.FuncDecl):
        return extractTypeAndName(t)

    name     = t.declname or defaultName or ''

    if isinstance(t.type, c_ast.Struct) \
    or isinstance(t.type, c_ast.Union) \
    or isinstance(t.type, c_ast.Enum):
        typename = t.type.name
    else:
        typename = t.type.names[0]

    return typename.lstrip('_'),d,name.lstrip('_')

Function = collections.namedtuple('Function', ('type', 'derefcnt', 'name', 'args'))
Argument = collections.namedtuple('Argument', ('type', 'derefcnt', 'name'))

Functions = {}

def Stringify(X):
    return '%s %s %s' % (X.type, X.derefcnt * '*', X.name)

def ExtractFuncDecl(node):
    # The function name needs to be dereferenced.
    ftype, fderef, fname = extractTypeAndName(node)

    if not fname:
        print "Skipping function without a name!"
        print node.show()
        return

    fargs = []
    for i, (argName, arg) in enumerate(node.args.children()):
        defname = 'arg%i' % i
        a = Argument(*extractTypeAndName(arg, defname))
        fargs.append(a)

    Functions[fname] = Func = Function(ftype, fderef, fname, fargs)

    if args.verbose:
        print Stringify(Func) + '(' + ','.join(Stringify(a) for a in Func.args) + ');'

class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDecl(self, node, *a):
        ExtractFuncDecl(node)

FuncDefVisitor().visit(ast)

print "Parsed %i functions" % len(Functions)

with open('functions.py','wt+') as f:
    f.write('''
import collections
Function = collections.namedtuple('Function', ('type', 'derefcnt', 'name', 'args'))
Argument = collections.namedtuple('Argument', ('type', 'derefcnt', 'name'))

functions = %s
'''.lstrip() % pprint.pformat(Functions))
