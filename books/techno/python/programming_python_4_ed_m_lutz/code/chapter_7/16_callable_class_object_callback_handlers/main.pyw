import sys
from tkinter import *


class HelloCallable:

    def __init__(self):
        self.msg = 'Hello __call__ world'

    def __call__(self):
        print(self.msg)
        sys.exit()


if __name__ == '__main__':
    widget = Button(None, text = 'Hello event world', command = HelloCallable())
    widget.pack()
    widget.mainloop()

