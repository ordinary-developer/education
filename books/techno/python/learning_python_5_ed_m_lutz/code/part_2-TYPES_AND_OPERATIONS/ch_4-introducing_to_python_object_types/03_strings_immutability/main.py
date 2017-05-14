if __name__ == '__main__':
    s = 'spam'
    print(s)
    # s[0] = 'z'
    s = 'z' + s[1:]
    print(s)
    print('-' * 50)

    s = 'shrubbery'
    l = list(s)
    print(l)
    l[0] = 'c'
    print(''.join(l))
    print('-' * 50)

    b = bytearray(b'spam')
    b.extend(b'eggs')
    print(b)
    print(b.decode())
