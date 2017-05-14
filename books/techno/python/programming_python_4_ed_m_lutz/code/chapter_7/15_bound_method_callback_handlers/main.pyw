import sys
from tkinter import *


class HelloClass:

    def __init__(self):
        widget = Button(None, text = 'hello event world', command = self.quit)
        widget.pack()

    def quit(self):
        print('Hello class method world')
        sys.exit()


if __name__ == '__main__':
    HelloClass()
    mainloop()
