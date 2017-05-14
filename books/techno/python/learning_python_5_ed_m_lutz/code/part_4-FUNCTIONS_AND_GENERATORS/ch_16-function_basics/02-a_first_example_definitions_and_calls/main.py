def example_1():
    def times(x, y):
        return x * y

    times(2, 4)

    x = times(3.14, 4)
    print(x)
    x = times(4, 3.14)
    print(x)

    print(times('Ni', 4))


if __name__ == '__main__':
    example_1()
