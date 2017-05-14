from tkinter import *
from user_preferences import bcolor, bfont, bsize


class ThemedButton(Button):

    def __init__(self, parent = None, **configs):
        Button.__init__(self, parent, **configs)
        self.pack()
        self.config(bg = bcolor, font = (bfont, bsize))


def onSpam():
    print('Spam')


def onEggs():
    print('Eggs')


class MyButton(ThemedButton):

    def __init__(self, parent = None, **configs):
        ThemedButton.__init__(self, parent, **configs)
        self.config(text = 'subclass')


if __name__ == '__main__':
    ThemedButton(text = 'spam', command = onSpam)
    ThemedButton(text = 'eggs', command = onEggs)
    MyButton(command = onSpam)
    mainloop()
