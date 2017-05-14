if __name__ == '__main__':
    from io import StringIO
    buff = StringIO()
    print(buff.write('spam\n'))
    print(buff.write('eggs\n'))
    print(buff.getvalue())

    buff = StringIO('ham\nspam\n')
    print(buff.readline())
    print(buff.readline())
    print(buff.readline())

    
    from io import StringIO
    import sys
    buff = StringIO()
    temp = sys.stdout
    sys.stdout = buff
    print(42, 'spam', 3.141)
    sys.stdout = temp
    print(buff.getvalue())

    from io import BytesIO
    stream = BytesIO()
    stream.write(b'spam')
    print(stream.getvalue())
    stream = BytesIO(b'dpam')
    print(stream.read())


