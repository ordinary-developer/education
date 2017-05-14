from tkinter import *


class someGuiClass:

    def __init__(self):
        self.X = 42
        self.Y = 'spam'
        Button(text = 'Hi', command = self.handler).pack()

    def handler(self):
        print(self.X)
        print(self.Y)


if __name__ == '__main__':
    gui = someGuiClass()
    gui.X = 84
    mainloop()
