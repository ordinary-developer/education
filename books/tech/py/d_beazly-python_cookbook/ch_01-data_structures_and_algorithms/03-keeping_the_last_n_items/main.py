def example_1():
    from collections import deque
    def search(lines, pattern, history = 5):
        prev_lines = deque(maxlen = history)
        for line in lines:
            if pattern in line:
                yield line, prev_lines
            prev_lines.append(line)

    with open('somefile.txt') as f:
        for line, prev_lines in search(f, 'python', 5):
            for prev_line in prev_lines:
                print(prev_line, end = '')
            print(line, end = '')
            print('-' * 20)


def example_2():
    from collections import deque
    q = deque(maxlen = 3)
    q.append(1)
    q.append(2)
    q.append(3)
    print(q)

    q.append(4)
    print(q)

    q.append(5)
    print(q)


def example_3():
    from collections import deque
    q = deque()
    q.append(1)
    q.append(2)
    q.append(3)
    print(q)

    q.appendleft(4)
    print(q)

    print(q.pop())
    print(q.popleft())


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
