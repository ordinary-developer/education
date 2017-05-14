if __name__ == '__main__':
    d = {'a': 1, 'b': 2, 'c': 3}
    print(d)
    
    d['e'] = 99
    print(d)

    # here an error will occur
    # print(d['f'])


    print('f' in d)
    if not 'f' in d:
        print('missing')
        print('no, really...')


    value = d.get('x', 0)
    print(value)

    value = d['x'] if 'x' in d else 0
    print(value)
