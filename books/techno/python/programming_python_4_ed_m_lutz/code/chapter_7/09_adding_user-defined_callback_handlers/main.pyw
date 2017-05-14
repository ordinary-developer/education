import sys
from tkinter import *


def quit():
    print('I must be going ...')
    sys.exit()


if __name__ == '__main__':
    widget = Button(None, text = 'hello world', command = quit)
    widget.pack()
    widget.mainloop()
