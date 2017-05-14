if __name__ == '__main__':
    import sys

    try:
        raise IndexError
    except:
        print(sys.exc_info())


    import traceback
    def grail(x):
        raise TypeError('already got one')

    try:
        grail('arthur')
    except:
        exc_info = sys.exc_info()
        print(exc_info[0])
        print(exc_info[1])
        traceback.print_tb(exc_info[2])
