if __name__ == '__main__':
    l = [123, 'spam', 'Ni']

    try:
        print(l[99])
    except IndexError:
        print("Index error 1")

    try:
        l[99] = 1
    except IndexError:
        print("Index error 2")

