if __name__ == '__main__':
    m = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]

    print([row[1] for row in m])
    print([row[1] + 1 for row in m])
    print([row[1] for row in m if row[1] % 2 == 0])

    print('-' * 50)


    print([m[i][i] for i in [0, 1, 2]])
    print([c * 2 for c in 'spam'])

    print('-' * 50)

    
    print(list(range(4)))
    print(list(range(-6, 7, 2)))
    print([[x ** 2, x ** 3] for x in range(4)])
    print([[x, x / 2, x ** 3] for x in range(-6, 7, 2) if x > 0])

    print('-' * 50)


    G = (sum(row) for row in m)
    print(next(G))
    print(next(G))
    print(next(G))

    print('-' * 50)


    print(list(map(sum, m)))

    print('-' * 50)


    print({sum(row) for row in m})
    print({i: sum(m[i]) for i in range(3)})

    print('-' * 50)
    

    print([ord(x) for x in 'spaam'])
    print({ord(x) for x in 'spaam'})
    print({x: ord(x) for x in 'spaam'})
    print((ord(x) for x in 'spaam'))
