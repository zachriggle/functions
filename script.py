from pwn import *
import pycparser

p = pycparser.parse_file(sys.argv[1])
