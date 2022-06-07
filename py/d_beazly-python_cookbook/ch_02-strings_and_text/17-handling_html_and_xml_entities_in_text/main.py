def example_1():
    s = 'Elements are written as "<tag>text</tag>".'
    import html
    print(s)
    print(html.escape(s))
    print(html.escape(s, quote = False))


def example_2():
    s = 'Spicy Jalapeño'
    print(s.encode('ascii', errors = 'xmlcharrefreplace'))


def example_3():
    s = 'Spicy &qout;Jalape&#241;o&quot.'
    from html.parser import HTMLParser
    p = HTMLParser()
    print(p.unescape(s))

    t = 'The prompt is &gt;&gt;&gt;'
    from xml.sax.saxutils import unescape
    print(unescape(t))


if __name__ == '__main__':
    example_1()
    print('-' * 75)

    example_2()
    print('-' * 75)

    example_3()
