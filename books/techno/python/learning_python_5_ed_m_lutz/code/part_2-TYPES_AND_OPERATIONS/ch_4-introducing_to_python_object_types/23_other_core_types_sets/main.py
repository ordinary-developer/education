if __name__ == '__main__':
    N = 25

    X = set('spam')
    Y = { 'h', 'a', 'm' }

    print(X, Y)

    print(X & Y)
    print(X | Y)
    print(X - Y)
    print(X > Y)
    print(Y > X)
    print(X > { 'a' })
    print(Y > { 'a' })
    print({ 'a' } > { 'a' })

    print({ n ** 2 for n in [1, 2, 3, 4]})

    print(N * '-')
    # -------------


    print(list(set([1, 2, 1, 3, 1])))
    print(set('spam') - set('ham'))
    print(set('spam') == set('asmp'))

    print(N * '-')
    # -------------


    print('p' in set('spam'))
    print('p' in 'spam')
    print('ham' in ['eggs', 'spam', 'ham'])

    print(N * '-')
