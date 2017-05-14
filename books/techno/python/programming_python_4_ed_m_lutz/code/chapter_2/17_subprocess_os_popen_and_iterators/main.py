if __name__ == '__main__':
    import os
    for line in os.popen('ls /'):
       print(line, end = '')

    I = os.popen('ls /')
    print(I)
    
    I = os.popen('ls /')
    print(I.__next__())

    I = os.popen('ls /')
    # here will be the error
    # print(next(I))

    I = os.popen('ls /')
    I = iter(I)
    print(I.__next__())
    print(next(I))
