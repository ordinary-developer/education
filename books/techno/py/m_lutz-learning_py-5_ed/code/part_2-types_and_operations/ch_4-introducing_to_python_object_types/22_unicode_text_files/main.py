if __name__ == '__main__':
    N = 25

    S = 'sp\xc4m'
    print(S)
    print(repr(S))
    print(str(S))
    print(len(S))
    print(S[2])
    print(repr(S[2]))
    print(str(S[2]))
    print(N * '-')

    file = open('unidata.txt', 'w', encoding = 'utf-8')
    file.write(S)
    file.close()
    text = open('unidata.txt', encoding = 'utf-8').read()
    print(text)
    print(repr(text))
    print(str(text))
    print(len(text))
    print(N * '-')

    raw = open('unidata.txt', 'rb').read()
    print(raw)
    print(repr(raw))
    print(str(raw))
    print(len(raw))
    print(N * '-')

    print(text.encode('utf-8'))
    print(raw.decode('utf-8'))
    print(N * '-')

    print(text.encode('latin-1'))
    print(text.encode('utf-16'))
    print(len(text.encode('latin-1')))
    print(len(text.encode('utf-16')))
    print(b'\xff\xfes\x00p\x00\xc4\x00m\x00'.decode('utf-16'))
    print(N * '-')

    # Python 2.X style
    import codecs
    print(codecs.open('unidata.txt', encoding = 'utf8').read())
    print(codecs.open('unidata.txt', 'rb').read())
    print(open('unidata.txt').read())
