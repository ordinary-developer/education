if __name__ == '__main__':
    symbols = 'abcdef'
    print(tuple(ord(symbol) for symbol in symbols))

    import array
    print(array.array('I', (ord(symbol) for symbol in symbols)))

    colors = ['black', 'white']
    sizes = ['S', 'M', 'L']
    for tshirt in ('%s %s' % (c, s) for c in colors for s in sizes):
        print(tshirt)
