def example_1():
    def drop_first_last(grades):
        first, *middle, last = grades
        return sum(middle) / len(middle)

    print(drop_first_last([15, 20, 25, 30]))


def example_2():
    record = ('Dave', 'dave@example.com', '111-111', '222-222')
    name, email, *phone_numbers = record
    print(name, email, phone_numbers)


def example_3():
    sales_record = [15, 25, 30]
    *trailing_qtrs, current_qtr = sales_record
    trailing_avg = sum(trailing_qtrs) / len(trailing_qtrs)
    print(trailing_qtrs, trailing_avg, current_qtr)

    
def example_4():
    records = [ ('foo', 1, 2),
                ('bar', 'hello'),
                ('foo', 3, 4) ]

    def do_foo(x, y):
        print('foo', x, y)

    def do_bar(s):
        print('bar', s)

    for tag, *args in records:
        if tag == 'foo':
            do_foo(*args)
        elif tag == 'bar':
            do_bar(*args)


def example_5():
    line = 'nobody:*:-2:-2:user:/var/empty:/usr/bin/false'
    uname, *fields, homedir, sh = line.split(':')
    print(uname, homedir, sh)


def example_6():
    record = ('ACME', 50, 123.45, (12, 18, 2012))
    name, *_, (*_, year) = record
    print(name, year)


def example_7():
    items = [1, 2, 3, 4, 5]
    head, *tail = items
    print(head, tail)


def example_8():
    def my_sum(items):
        head, *tail = items
        return head + my_sum(tail) if tail else head

    print(my_sum([1, 2, 3, 4, 5]))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
    example_7()
    example_8()
