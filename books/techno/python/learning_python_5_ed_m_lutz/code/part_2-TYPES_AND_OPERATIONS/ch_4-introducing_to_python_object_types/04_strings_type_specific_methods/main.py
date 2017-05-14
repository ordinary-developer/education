if __name__ == '__main__':
    s = 'spam'
    print(s)
    print(s.find('pa'))
    print(s.replace('pa', 'XYZ'))
    print('-' * 25)

    line = 'aaa,bbb,ccc,ddd'
    print(line.split(','))
    s = 'spam'
    print(s.upper())
    print(s.isalpha())
    print(s.isdigit())
    line = 'aaa,bbb,ccc,ddd\n'
    print(repr(line))
    print(repr(line.rstrip()))
    print(line.rstrip().split(','))
    print('-' * 50)

    print('%s, eggs, and %s' % ('spam', 'SPAM!'))
    print('{0}, eggs, and {1}'.format('spam', 'SPAM!'))
    print('{}, eggs, and {}'.format('spam', 'SPAM!'))
