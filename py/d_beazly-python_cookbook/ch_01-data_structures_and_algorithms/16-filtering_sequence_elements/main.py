def example_1():
    mylist = [1, 4, -5, 10, -7, 2, 3, -1]

    print([n for n in mylist if n > 0])
    print([n for n in mylist if n < 0])

def example_2():
    mylist = [1, 4, -5, 10, -7, 2, 3, -1]

    positive_numbers = (n for n in mylist if n > 0)
    for number in positive_numbers:
        print(number)


def example_3():
    values = ['1', '2', '-3', '4', 'N/A', '5']

    def is_int(value):
        try:
            x = int(value)
            return True
        except ValueError:
            return False

    print(list(filter(is_int, values)))


def example_4():
    mylist = [1, 4, -5, 10, -7, 2, 3, -1]

    clip_neg = [n if n > 0 else 0 for n in mylist]
    clip_pos = [n if n < 0 else 0 for n in mylist]
    print(clip_neg)
    print(clip_pos)


def example_5():
    addresses = [
        '5412 N CLARK',
        '5148 N CLARK',
        '5800 E 58TH',
        '2122 N CLARK',
        '5645 N RAVENSWOOD',
        '1060 W ADDISON',
        '4801 N BROADWAY',
        '1039 W GRANVILLE'
    ]

    counts = [0, 3, 10, 4, 1, 7, 6, 1]

    from itertools import compress
    more5 = [n > 5 for n in counts]
    print(list(compress(addresses, more5)))



if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
