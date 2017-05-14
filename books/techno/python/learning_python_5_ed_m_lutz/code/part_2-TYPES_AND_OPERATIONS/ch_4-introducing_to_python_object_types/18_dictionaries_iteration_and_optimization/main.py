if __name__ == '__main__':
    squares = [x ** 2 for x in [1, 2, 3, 4, 5]]
    print(squares)

    squares = []
    for x in [1, 2, 3, 4, 5]:
        squares.append(x ** 2)
    print(squares)
