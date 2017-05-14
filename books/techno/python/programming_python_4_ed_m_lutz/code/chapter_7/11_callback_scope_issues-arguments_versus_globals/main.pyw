from tkinter import *


def handler(A):
    print(A)


if __name__ == '__main__':
    X = 42
    widget = Button(text = 'ni', command = (lambda: handler('spam')))
    widget.pack()
    widget.mainloop()
