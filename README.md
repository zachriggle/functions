# functions

Python repository containing parsed standard C library function and argument information

## How do I use it?

I already did the heavy lifting for you, just look at [functions.py][1].

If you want to build it yourself, just clone the repo and `make clean all`.

Things will probably blow up, which is why I included a `Dockerfile`.  You can build with `make release`.

[1]: https://github.com/zachriggle/functions/blob/master/functions.py

## Example

```
>>> from functions import functions
>>> print functions['memcpy']
Function(type='void', derefcnt=1, name='memcpy', args=[Argument(type='void', derefcnt=1, name='dest'), Argument(type='void', derefcnt=1, name='src'), Argument(type='size_t', derefcnt=0, name='n')])
>>> print functions['memcpy'].args
[Argument(type='void', derefcnt=1, name='dest'), Argument(type='void', derefcnt=1, name='src'), Argument(type='size_t', derefcnt=0, name='n')]
>>> print functions['memcpy'].args[0]
Argument(type='void', derefcnt=1, name='dest')
>>> print functions['memcpy'].type
void
>>> print functions['memcpy'].derefcnt
1
```

## Notes

Basically we just pass everything to `PyCParser` and extract all functions and arguments, as well as their types.

Some syscalls are not in any standard C headers, so these have been added to `missing.txt`.  The signatures are manually (pun!) extracted from the man pages.
