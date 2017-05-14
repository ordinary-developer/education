def example_1():
    def dedupe(items):
        seen = set()
        for item in items:
            if item not in seen:
                yield item
                seen.add(item)

    a = [1, 5, 2, 1, 9, 1, 5, 10]
    print(list(dedupe(a)))


def example_2():
    def dedupe(items, key = None):
        seen = set()
        for item in items:
            value = item if key is None else key(item)
            if value not in seen:
                yield item
                seen.add(value)

    a = [{'x': 1, 'y': 2}, {'x': 1, 'y': 3}, {'x': 1, 'y': 2}, {'x': 2, 'y': 4}]
    print(list(dedupe(a, key = lambda d: (d['x'], d['y']))))
    print(list(dedupe(a, key = lambda d: d['x'])))


def example_3():
    a = [1, 5, 2, 1, 9, 1, 5, 10]
    print(set(a))
    

if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
