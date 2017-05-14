from array import array
from random import random

def example_1():
    floats = array('d', (random() for i in range(10 ** 7)))
    print(floats[-1])
    fp = open('floats.bin', 'wb')
    floats.tofile(fp)
    fp.close()
    floats2 = array('d')
    fp = open('floats.bin', 'rb')
    floats2.fromfile(fp, 10**7)
    fp.close()
    print(floats2[-1])
    print(floats2 == floats)


if __name__ == '__main__':
    example_1()
