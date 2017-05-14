def example_1():
    l = [1, 2, 3]
    print(l * 5)
    print(5 * 'abcd')


def example_2():
    board = [['_'] * 3 for i in range(3)]
    print(board)
    board[1][2] = 'X'
    print(board)


def example_3():
    weird_board = [['_'] * 3] * 3
    print(weird_board)
    weird_board[1][2] = '0'
    print(weird_board)


def example_4():
    row = ['_'] * 3
    board = []
    for i in range(3):
        board.append(row)
    print(board)
    board[2][0] = 'X'
    print(board)

    board = []
    for i in range(3):
        row = ['_'] * 3
        board.append(row)
    print(board)
    board[2][0] = 'X'
    print(board)

    

if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()

