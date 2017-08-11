def intersect(*args):
    res = []
    for x in args[0]:
        if x in res: 
            continue
        for other in args[1:]:
            if x not in other: 
                break
            else:
                res.append(x)
    return res

def union(*args):
    res = []
    for seq in args:
        for x in seq:
            if not x in res:
                res.append(x)
    return res


def example1():
    s1, s2, s3 = "SPAM", "SCAM", "SLAM"
    print(intersect(s1, s2), union(s1, s2))
    print(intersect([1, 2, 3], (1, 4)))
    print(intersect(s1, s2, s3))
    print(union(s1, s2, s3))


def example2():
    def tester(func, items, trace = True):
        for i in range(len(items)):
            items = items[1:] + items[:1]
            if trace:
                print(items)
            print(sorted(func(*items)))

    tester(intersect, ('a', 'abcdefg', 'abdst', 'albmcnd'))
    tester(union, ('a', 'abcdef', 'abdst', 'albmcnd'), False)
    tester(intersect, ('ba', 'abcdefg', 'abdst', 'albmcnd'), False)
    
    print(intersect([1, 2, 1, 3], (1, 1, 4)))
    print(union([1, 2, 1, 3], (1, 1, 4)))
    print(tester(intersect, ('ababa', 'abcdefga', 'aaaab'), False))


if __name__ == '__main__':
    example1()    
    example2()
