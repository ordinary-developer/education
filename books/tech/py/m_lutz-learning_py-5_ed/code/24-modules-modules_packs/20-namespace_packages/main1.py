import sub
print(sub)
print(sub.__path__)

from sub import mod1
print(mod1)

import sub.mod2
print(sub.mod2)
