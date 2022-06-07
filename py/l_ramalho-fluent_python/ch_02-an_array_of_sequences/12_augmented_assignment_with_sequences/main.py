def example_1():
    l = [1, 2, 3]
    print(id(l))
    l *= 2
    print(l)
    print(id(l))
    t = (1, 2, 3)
    print(id(t))
    t *= 2
    print(id(t))


def example_2():
   dis.dis('s[a] += b') 

if __name__ == '__main__':
    example_1()
    example_2()

    
