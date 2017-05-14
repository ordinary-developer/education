if __name__ == '__main__':
    # python 3.X strings
    print('sp\xc4m')
    print(b'a\x01c')
    print(u'sp\u00c4m')
    print('-' * 25)

    print('spam')
    print('spam'.encode('utf8'))
    print('spam'.encode('utf16'))
    print('-' * 25)

    print('sp\xc4\u00c4\U000000c4m')
    print('-' * 25)

    print('\u00A3', '\u00A3'.encode('latin1'), b'\xA3'.decode('latin1'))
    print('-' * 25)

    print(u'x' + 'y')
    print('x' + b'y'.decode())
    print('x'.encode() + b'y')
