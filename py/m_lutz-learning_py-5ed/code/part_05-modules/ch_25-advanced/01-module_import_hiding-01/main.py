from unders import *
print(a, c)

try:
    print(_b)
except NameError:
    print('cannot import _b')

import unders
print(unders._b)
