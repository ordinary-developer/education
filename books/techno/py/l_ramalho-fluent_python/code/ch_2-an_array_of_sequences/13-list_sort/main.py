def example_1():
    fruits = ['grape', 'rasberry', 'apple', 'banana']
    print(sorted(fruits))
    print(fruits)
    print(sorted(fruits, reverse = True))
    print(sorted(fruits, key = len))
    print(sorted(fruits, key = len, reverse = True))
    print(fruits)
    print(fruits.sort())
    print(fruits)


if __name__ == '__main__':
    example_1()
