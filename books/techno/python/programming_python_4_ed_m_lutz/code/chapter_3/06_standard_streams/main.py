import sys

if __name__ == '__main__':
    for f in (sys.stdin, sys.stdout, sys.stderr):
        print(f)

    print('hello stdout world')
    sys.stdout.write('hello stdout world' + '\n')

    input('hello stdin world>')
    print('hello stdin world>')
    sys.stdin.readline()[:-1]
