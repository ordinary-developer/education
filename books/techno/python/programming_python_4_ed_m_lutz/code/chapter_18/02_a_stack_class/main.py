if __name__ == '__main__':
    from stack2 import Stack
    x = Stack()
    x.push('spam')
    x.push(123)
    print(x)

    y = Stack()
    y.push(3.1415)
    y.push(x.pop())
    print(x)
    print(y)

    z = Stack()
    for c in 'spam':
        z.push(c)
    while z:
        print(z.pop(), end = ' ')
    print()

    z = x + y
    print(z)
    for item in z:
        print(item, end = ' ')
    print()

