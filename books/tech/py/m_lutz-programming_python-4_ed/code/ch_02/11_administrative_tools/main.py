if __name__ == '__main__':
    import os

    print(os.getpid())
    print(os.getcwd())
    os.chdir(r'/home/ivan')
    print(os.getcwd())

    print(os.pathsep)
    print(os.sep)
    print(os.pardir)
    print(os.curdir)
    print(os.linesep)
    print(repr(os.linesep))
