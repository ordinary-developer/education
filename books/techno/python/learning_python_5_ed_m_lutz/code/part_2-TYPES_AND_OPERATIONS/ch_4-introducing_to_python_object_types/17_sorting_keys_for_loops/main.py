if __name__ == '__main__':
    d = {'a': 1, 'b': 2, 'c': 3}
    print(d)
    print("=" * 25)


    ks = list(d.keys())
    print(ks)
    ks.sort()
    print(ks)
    for key in ks:
        print(key, '=>', d[key])
    print('=' * 25)


    print(d)
    for key in sorted(d):
        print(key, '=>', d[key])
    print(sorted(d))
    print('=' * 25)


    for c in 'spam':
        print(c.upper())
    print('=' * 25)

    x = 4
    while x > 0:
        print('spam!' * x)
        x -= 1
