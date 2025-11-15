# online C++ compilers
https://replit.com/
https://www.online-cpp.com/
https://coliru.stacked-crooked.com/
https://cpp.sh/
https://wandbox.org/
https://onecompiler.com/cpp
https://www.codechef.com/ide
https://www.codingrooms.com/compiler/cpp

https://godbolt.org/
https://www.onlinegdb.com/online_c++_compiler

https://codeinterview.io/
https://codeanywhere.com/

# miscellaneous
the command for the `coliru` compler:
```sh
> g++ -std=c++23 -O2 -Wall -pedantic -pthread main.cpp && ./a.out
```

or more detailed:
```sh
g++ -std=c++23  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors main.cpp -lm  -latomic  && ./a.out
```
