To build a qt project with UI creation in code and with the .qrc file:

0. enter the project directory
```sh
$ cd project_dir
```

1. run
```sh
$ qmake -project
```

2. after that a pro-file with the name of directory will be generated
add the next strings to this file (to the common section, it is without name):
```
QT += widgets
QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra -pedantic
```

add the next line to the input section (with the comment '#input'):
```
RESOURCES = images.qrc
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

