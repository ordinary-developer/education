from tkinter import *


class ThemedButton(Button):

    def __init__(self, parent = None, **config):
        Button.__init__(self, parent, **config)
        self.pack()
        self.config(fg = 'red', bg = 'black', font = ('courier', 12), 
                relief = RAISED, bd = 5)


def onSpam():
    print('Spam')


if __name__ == '__main__':
    B1 = ThemedButton(text = 'spam', command = onSpam)
    B2 = ThemedButton(text = 'eggs')
    B2.pack(expand = YES, fill = BOTH)
    mainloop()
