def example_1():
    def min1(*args):
        res = args[0]
        for arg in args[1:]:
            if arg < res:
                res = arg
        return res

    def min2(first, *rest):
        for arg in rest:
            if arg < first:
                first = arg
        return first

    def min3(*args):
        tmp = list(args)
        tmp.sort()
        return tmp[0]


    print(min1(3, 4, 1, 2))    
    print(min2("bb", "aa"))
    print(min3([2, 2], [1, 1], [3, 3]))


def example_2():
    def minmax(test, *args):
        res = args[0]
        for arg in args[1:]:
            if test(arg, res):
                res = arg
        return res

    def lessthan(x, y): return x < y
    def grtrthan(x, y): return x > y

    print(minmax(lessthan, 4, 2, 1, 5, 6, 3))
    print(minmax(grtrthan, 4, 2, 1, 5, 6, 3))


if __name__ == '__main__':
    example_1()
    example_2()
