if __name__ == '__main__':
    file = open('spam.txt', 'w')
    print(file.write(('spam' * 5) + '\n'))
    print(file.write(('spam' * 5) + '\n'))
    file.close()
    file  =open('spam.txt')
    text = file.read()
    print(text)
    file.close()

    file = open('spam.txt')
    text = file.read(15)
    print(text)
    file.close()

    file = open('spam.txt')
    text = file.readlines()
    print(text)
    file.close()

    file = open('spam.txt')
    text = file.readline()
    while text:
        print(text)
        text = file.readline()
    file.close()

    # --------
    print('-' * 25)
    # --------

    file = open('spam.txt', 'w')
    file.write(('spam' * 5) + '\n')
    file.write(('spam' * 5) + '\n')
    file.close()

    file = open('spam.txt')
    text = file.read()
    print(text)
    file.close()

    file = open('spam.txt')
    text = file.read(10)
    print(text)
    file.close()

    file = open('spam.txt')
    text = file.readlines()
    print(text)
    file.close()

    file = open('spam.txt')
    line = file.readline()
    while line:
        print(line)
        line = file.readline()
    file.close()

