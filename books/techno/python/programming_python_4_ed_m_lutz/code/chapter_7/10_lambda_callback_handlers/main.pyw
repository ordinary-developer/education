import sys
from tkinter import *


if __name__ == '__main__':
    widget = Button(None, text = 'hello world',
            command = (lambda: print('hello lambda world') or sys.exit()))
    widget.pack()
    widget.mainloop()
