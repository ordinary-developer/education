# common issues 

- MOC parses only header files.
- Each class that has signals and slots 
  must be inherited from QObject (may be indirectly).
  The macro "Q_OBJECT" must be at the beginning of the class.


## qt prerequisites
for successful qt building you must install
```sh
$ sudo apt-get install build-essential libg1-messa-dev
```

