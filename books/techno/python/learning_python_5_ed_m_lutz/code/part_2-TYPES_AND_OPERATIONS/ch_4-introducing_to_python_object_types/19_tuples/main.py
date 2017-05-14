if __name__ == '__main__':
    t = (1, 2, 3, 4)

    print(t)
    print(len(t))
    print(t + (5, 6))
    print(t[0])

    print(t.index(4))
    print(t.count(4))

    # here an error will ocurr
    # t[0] = 2
    t = (2, ) + t[1:]
    print(t)

    t = 'spam', 3.0, [11, 22, 33]
    print(t[1])
    print(t[2][1])
    # here an error will ocurrk
    # print(t.append(4))
