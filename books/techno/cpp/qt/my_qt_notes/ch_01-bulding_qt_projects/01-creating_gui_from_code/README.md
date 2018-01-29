To build a qt project with UI creation in code

0. enter the project directory
```sh
$ cd project_dir
```

1. run
```sh
$ qmake -project
```

2. after that a pro-file with the name of directory will be generated
add the next strings to this file:
```
QT += widgets
QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra -pedantic
```

(if you want to compile by another compiler (not gcc)
 specify your own parameters)

3. After that run the next command to create a makefile:
```sh
$ qmake
```

4. After that run the next command:
```sh
$ make
```

for parallel compiling run
```sh
$ make --jobs 4
```
