if __name__ == '__main__':
    import os
    print(open('helloshell.py').read())
    text = os.popen('cat helloshell.py').read()
    print(text)
    listings = os.popen('ls').readlines()
    print(listings)

    print(os.system('~/shortcuts/python helloshell.py'))
    output = os.popen('~/shortcuts/python helloshell.py').read()
    print(output)

    print('#' * 30)
    print(open('helloshell.py').read())
    text = os.popen('cat helloshell.py').read()
    print(text)
    listings = os.popen('ls').readlines()
    print(listings)

    print(os.system('~/shortcuts/python helloshell.py'))
    output = os.popen('~/shortcuts/python helloshell.py').read()
    print(output)
