if __name__ == '__main__':
    import sys

    print(sys.platform)
    print(sys.maxsize)
    print(sys.version)

    if sys.platform[:3] == 'lin':
        print('hello linux')
