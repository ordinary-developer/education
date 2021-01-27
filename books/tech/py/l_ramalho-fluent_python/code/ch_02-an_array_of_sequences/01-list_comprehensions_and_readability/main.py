if __name__ == '__main__':
    symbols = 'abcdef'
    codes = []
    for symbol in symbols:
        codes.append(ord(symbol))
    print(codes)

    symbols = 'abcdef'
    codes = [ord(symbol) for symbol in symbols]
    print(codes)

