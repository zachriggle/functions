import collections
import pprint
from pwn import *
from pycparser import *
from pycparser import parse_file

ast = parse_file(sys.argv[1])


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

    name     = t.declname

    if isinstance(t.type, c_ast.Struct) \
    or isinstance(t.type, c_ast.Union) \
    or isinstance(t.type, c_ast.Enum):
        typename = t.type.name
    else:
        typename = t.type.names[0]

    if name:
        name = name.lstrip('_')
    else:
        name = defaultName

    return typename,d,name

Function = collections.namedtuple('Function', ('type', 'derefcnt', 'name'))
Argument = collections.namedtuple('Argument', ('type', 'derefcnt', 'name'))

Functions = {}

def ExtractFuncDecl(node):
    # The function name needs to be dereferenced.
    f= Function(*extractTypeAndName(node))

    Functions[f] = []

    for i, (argName, arg) in enumerate(node.args.children()):
        defname = 'arg%i' % i
        a = Argument(*extractTypeAndName(arg, defname))
        Functions[f].append(a)



class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDecl(self, node, *a):
        ExtractFuncDecl(node)

FuncDefVisitor().visit(ast)

def Stringify(X):
    return '%s %s %s' % (X.type, X.derefcnt * '*', X.name)

for Func, Args in Functions.items():
    print Stringify(Func) + '(' + ','.join(Stringify(a) for a in Args) + ');'

with open('functions.py','wt+') as f:
    f.write('''
import collections
Function = collections.namedtuple('Function', ('type', 'derefcnt', 'name'))
Argument = collections.namedtuple('Argument', ('type', 'derefcnt', 'name'))

functions = %s
''' % pprint.pformat(Functions))
