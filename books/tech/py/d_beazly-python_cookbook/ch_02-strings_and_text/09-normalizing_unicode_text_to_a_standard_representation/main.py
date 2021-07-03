def example_1():
    s1 = 'Spicy Jalape\u00f1o'
    s2 = 'Spicy Jalapen\u0303o'
    print(s1)
    print(s2)
    print(s1 == s2)
    print(len(s1))
    print(len(s2))


def example_2():
    s1 = 'Spicy Jalape\u00f1o'
    s2 = 'Spicy Jalapen\u0303o'

    import unicodedata
    t1 = unicodedata.normalize('NFC', s1)
    t2 = unicodedata.normalize('NFC', s2)
    print(t1 == t2)
    print(ascii(t1))
    print(ascii(t2))

    t3 = unicodedata.normalize('NFD', s1)
    t4 = unicodedata.normalize('NFD', s2)
    print(t3 == t4)
    print(ascii(t3))
    print(ascii(t4))


def example_3():
    s = '\ufb01'
    print(s)
    
    import unicodedata
    print(unicodedata.normalize('NFD', s))
    print(unicodedata.normalize('NFKD', s))
    print(unicodedata.normalize('NFKC', s))


def example_4():
    s1 = 'Spicy Jalape\u00f1o'

    import unicodedata
    t1 = unicodedata.normalize('NFD', s1)
    print(''.join(c for c in t1 if not unicodedata.combining(c)))
    

if __name__ == '__main__':
    example_1()
    print('-' * 75)

    example_2()
    print('-' * 75)

    example_3()
    print('-' * 75)

    example_4()
    print('-' * 75)
