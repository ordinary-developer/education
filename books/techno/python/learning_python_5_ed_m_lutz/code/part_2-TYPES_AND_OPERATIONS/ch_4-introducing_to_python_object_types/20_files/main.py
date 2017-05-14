if __name__ == '__main__':
    f = open('data.txt', 'w')
    f.write('hello\n')
    f.write('world\n')
    f.close()

    f = open('data.txt')
    text = f.read()
    print(text)
    print(str(text))
    print(repr(text))
    print(text.split())

    for line in open('data.txt'):
        print(line)

    print(dir(f))
    help(f.seek)
