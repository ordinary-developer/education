if __name__ == '__main__':
    s = 'spam'
    print(dir(s))
    print(dir(str))
    print(s + 'ni!')
    print(s.__add__('ni!'))
    print(help(s.replace))
    print(help(str.replace))
