def example01():
    print(ord('s'))

    res = []
    for x in 'spam':
        res.append(ord(x))
    print(res)

    res = list(map(ord, 'spam'))
    print(res)

    res = [ord(x) for x in 'spam']
    print(res)


def example02():
    res = [x ** 2 for x in range(10)]
    print(res)

    res = list(map((lambda x: x ** 2), range(10)))
    print(res)


def example03():
    res = [x for x in range(5) if x % 2 == 0]
    print(res)

    res = list(filter((lambda x: x % 2 == 0), range(5)))
    print(res)

    res = []
    for x in range(5):
        if x % 2 == 0:
            res.append(x)
    print(res)


def example04():
    res = [x ** 2 for x in range(10) if x % 2 == 0]
    print(res)

    res = list(map((lambda x: x ** 2),filter((lambda x: x % 2 == 0),range(10))))
    print(res)


def example05():
    res = [x + y for x in [0, 1, 2] for y in [100, 200, 300]]
    print(res)

    res = []
    for x in [0, 1, 2]:
        for y in [100, 200, 300]:
            res.append(x + y)
    print(res)


def example06():
    res = [x + y for x in 'spam' for y in 'SPAM']
    print(res)

    res = [x + y for x in 'spam' if x in 'sm' for y in 'SPAM' if y in 'PA']
    print(res)

    res = [x + y + z for x in 'spam' if x in 'sm'
                     for y in 'SPAM' if y in 'PA'
                     for z in '123'  if z > '1']
    print(res)


def example07():
    res = \
      [(x, y) for x in range(5) if x % 2 == 0 for y in range(5) if y % 2 == 1]
    print(res)

    res = []
    for x in range(5):
        if x % 2 == 0:
            for y in range(5):
                if y % 2 == 1:
                    res.append((x, y))
    print(res)

    
def example08():
    M = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]
    N = [[2, 2, 2],
         [3, 3, 3],
         [4, 4, 4]]

    print(M[1], M[1][2])

    print([row[1] for row in M])
    print([M[row][1] for row in (0, 1, 2)])

    print([M[i][i] for i in range(len(M))])
    print([M[i][len(M) - 1 - i] for i in range(len(M))])

    L = [[1, 2, 3], [4, 5, 6]]
    for i in range(len(L)):
        for j in range(len(L[i])):
            L[i][j] += 10
    print(L)

    print([col + 10 for row in M for col in row])                     
    print([[col + 10 for col in row] for row in M])

    res = []
    for row in M:
        for col in row:
            res.append(col + 10)
    print(res)

    res = []
    for row in M:
        tmp = []
        for col in row:
            tmp.append(col + 10)
        res.append(tmp)
    print(res)

    print([M[row][col] * N[row][col] for row in range(3) for col in range(3)])
    print([[M[row][col] * N[row][col] for col in range(3)] for row in range(3)])

    res = []
    for row in range(3):
        tmp = []
        for col in range(3):
            tmp.append(M[row][col] * N[row][col])
        res.append(tmp)
    print(res)

    res = [[col1 * col2 for (col1, col2) in zip(row1, row2)] 
           for (row1, row2) in zip(M, N)]
    print(res)

    res = []
    for (row1, row2) in zip(M, N):
        tmp = []
        for (col1, col2) in zip(row1, row2):
            tmp.append(col1 * col2)
        res.append(tmp)
    print(res)


if __name__ == '__main__':
    examples = [ example01, example02, example03, example04, example05,
                 example06, example07, example08 ]

    for example in examples:
        example()
