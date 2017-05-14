def example_1():
    import random

    for i in range(0, 10):
        test = random.choice([True, False])
        if test:
            def f():
                print('test is equal to true')
        else:
            def f():
                print('test is equal to false')
        f()


def example_2():
    def f():
        print('simple function')

    otherfunc = f
    otherfunc()


def example_3():
    def f():
        print('another simple function')

    f()

    f.attr_name = '1'
    print(f.attr_name)


if __name__ == '__main__':
    example_1()    
    example_2()
    example_3()
