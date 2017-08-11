def example1():
    def mysum(L):
        if not L:
            return 0
        else:
            return L[0] + mysum(L[1:])

    print(mysum([1, 2, 3, 4, 5]))


def example2():
    def mysum(L):
        print(L)
        if not L:
            return 0
        else:
            return L[0] + mysum(L[1:])

    mysum([1, 2, 3, 4, 5])


def example3():
    def mysum(L):
        return 0 if not L else L[0] + mysum(L[1:])

    print(mysum([1, 2, 3, 4, 5]))
    print(mysum([]))
    print(mysum(None))
    print(mysum([1]))


def example4():
    def mysum(L):
        return L[0] if len(L) == 1 else L[0] + mysum(L[1:])

    print(mysum([1, 2, 3, 4, 5]))
    print(mysum(('s', 'p', 'a', 'm')))
    print(mysum(['spam', 'ham', 'eggs']))


def example5():
    def mysum(L):
        first, *rest = L
        return first if not rest else first + mysum(rest)

    print(mysum([1, 2, 3, 4, 5]))
    print(mysum(('s', 'p', 'a', 'm')))
    print(mysum(['spam', 'ham', 'eggs']))


def example6():
    def mysum(L):
        if not L: 
            return 0
        return nonempty(L)

    def nonempty(L):
        return L[0] + mysum(L[1:])

    print(mysum([1.1, 2.2, 3.3, 4.4]))


def example7():
    L = [1, 2, 3, 4, 5]
    sum = 0
    while L:
        sum += L[0]
        L = L[1:]
    print(sum)


def example8():
    L = [1, 2, 3, 4, 5]
    sum = 0
    for x in L:
        sum += x
    print(sum)


def example9():
    def sumtree(L):
        tot = 0
        for x in L:
            if not isinstance(x, list):
                tot += x
            else:
                tot += sumtree(x)
        return tot

    L = [1, [2, [3, 4], 5], 6, [7, 8]]
    print(sumtree(L))

    print(sumtree([1, [2, [3, [4, [5]]]]]))
    print(sumtree([[[[[1], 2], 3], 4], 5]))


def example10():
    def sumtree(L):
        tot = 0
        items = list(L)
        while items:
            front = items.pop(0)
            if not isinstance(front, list):
                tot += front
            else:
                items.extend(front)
        return tot

    L = [1, [2, [3, 4], 5], 6, [7, 8]]
    print(sumtree(L))


def example11():
    def sumtree(L):
        total = 0
        items = list(L)
        while items:
            front = items.pop(0)
            if not isinstance(front, list):
                total += front
            else:
                items[:0] = front
        return total

    L = [1, [2, [3, 4], 5], 6, [7, 8]]
    print(sumtree(L))

    
if __name__ == '__main__':
    example1()
    example2()
    example3()
    example4()
    example5()
    example6()
    example7()
    example8()
    example9()
    example10()
    example11()
