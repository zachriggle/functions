import argparse
import collections
import pprint
from pwn import *
from pycparser import *
from pycparser import parse_file

from funcparser import ExtractAllFuncDecls

p = argparse.ArgumentParser(description='''
Parse a header file into Python to extract the function signatures
''')

p.add_argument('file')
p.add_argument('-v','--verbose',action='store_true')

args = p.parse_args()

ast = parse_file(args.file)
Functions = ExtractAllFuncDecls(ast, verbose=args.verbose)

print "Parsed %i functions" % len(Functions)

with open('functions.py','wt+') as f:
    f.write('''
import collections
Function = collections.namedtuple('Function', ('type', 'derefcnt', 'name', 'args'))
Argument = collections.namedtuple('Argument', ('type', 'derefcnt', 'name'))

functions = %s
'''.lstrip() % pprint.pformat(Functions))
