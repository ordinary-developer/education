if __name__ == '__main__':  
    symbols = 'abcdef'
    in_ascii = [ord(s) for s in symbols if ord(s) < 127]
    print(in_ascii)

    in_ascii = list(filter(lambda c: c < 127, map(ord, symbols)))
    print(in_ascii)
