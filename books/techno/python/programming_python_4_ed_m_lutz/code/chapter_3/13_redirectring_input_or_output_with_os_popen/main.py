if __name__ == '__main__':
    import os
    pipe = os.popen('/home/ivan/shortcuts/python hello-out.py')
    print(pipe.read())
    print(pipe.close())

    pipe = os.popen('/home/ivan/shortcuts/python hello-in.py', 'w')
    print(pipe.write('Gumby\n'))
    pipe.close()
    print(open('hello-in.txt').read())
