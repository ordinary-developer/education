from tkinter import *


def handler(A, B):
    print(A)
    print(B)


def makegui():
    X = 42
    Button(text = 'ni', command = (lambda: handler(X, 'spam'))).pack()


if __name__ == '__main__':
    makegui()
    mainloop()
