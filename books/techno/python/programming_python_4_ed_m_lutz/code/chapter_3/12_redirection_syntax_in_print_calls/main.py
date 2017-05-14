if __name__ == '__main__':
    import sys
    print('spam' * 2, file = sys.stderr)

    from io import StringIO
    buff = StringIO()
    print(42, file = buff)
    print('spam', file = buff)
    print(buff.getvalue())
