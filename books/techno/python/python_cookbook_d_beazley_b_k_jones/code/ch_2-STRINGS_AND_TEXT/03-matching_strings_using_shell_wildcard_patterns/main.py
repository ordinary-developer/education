def example_1():
    names = ['Dat1.csv', 'Dat2.csv', 'config.ini', 'foo.py']

    from fnmatch import fnmatch, fnmatchcase
    print(fnmatch('foo.txt', '*.txt'))
    print(fnmatch('foo.txt', '?oo.txt'))
    print(fnmatch('Dat45.csv', 'Dat[0-9]*'))
    print([name for name in names if fnmatch(name, 'Dat*.csv')])


def example_2():
    from fnmatch import fnmatch, fnmatchcase

    print(fnmatch('foo.txt', '*.txt'))
    print(fnmatch('foo.txt', '*.TXT'))
    print(fnmatch('foo.txt', '*.TXT'))


def example_3():
    addresses = [
        '5412 N CLARK ST',
        '1060 W ADDISON ST',
        '1039 W GRANVILLE AVE',
        '2122 N CLARK ST',
        '4802 N BROADWAY'
    ]

    from fnmatch import fnmatchcase
    print([addr for addr in addresses if fnmatchcase(addr, '* ST')])
    print([addr for addr in addresses if fnmatchcase(addr,
                                                     '54[0-9][0-9] *CLARK*')])



if __name__ == '__main__':
    example_1()
    print(75 * '-')

    example_2()
    print(75 * '-')
    
    example_3()
    print(75 * '-')
