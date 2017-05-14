def example_1():
    from collections import OrderedDict

    d = OrderedDict()
    d['foo'] = 1
    d['bar'] = 2
    d['spam'] = 3
    d['grok'] = 4
    for key in d:
        print(key, d[key])

    import json
    print(json.dumps(d))


if __name__ == '__main__':
    example_1()

