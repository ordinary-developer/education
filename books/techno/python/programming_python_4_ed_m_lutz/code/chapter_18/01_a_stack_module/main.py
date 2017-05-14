if __name__ == '__main__':
    import stack1
    stack1.push('spam')
    stack1.push(123)
    print(stack1.top())
    print(stack1.stack)

    stack1.pop()
    stack1.dump()
    stack1.pop()
    print(stack1.empty())

    for c in 'spam':
        stack1.push(c)
    while not stack1.empty():
        print(stack1.pop(), end = ' ')
    print()

    try:
        stack1.pop()
    except stack1.error:
        print('Here an error was ocurred')

    for c in 'spam':
        stack1.push(c)
    stack1.dump()
    for i in range(stack1.length()):
        print(stack1.item(i), end = ' ')
    print()

