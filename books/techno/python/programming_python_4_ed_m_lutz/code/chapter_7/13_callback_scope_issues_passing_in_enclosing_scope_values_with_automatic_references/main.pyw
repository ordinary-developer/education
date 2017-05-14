from tkinter import *


class Gui:

    def handler(self, A, B):
        print(A)
        print(B)

    def makegui(self):
        X = 42
        Button(text = 'ni', command = (lambda: self.handler(X, 'spam'))).pack()


if __name__ == '__main__':
    Gui().makegui()
    mainloop()
