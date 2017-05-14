from tkinter import *
from sys import exit


class Hello(Frame):

    def __init__(self, parent = None):
        Frame.__init__(self, parent)
        self.pack()
        self.data = 42
        self.make_widgets()

    def make_widgets(self):
        widget = Button(self, text = 'Hello frame world!',
                command = self.message)
        widget.pack(side = LEFT)

    def message(self):
        self.data += 1
        print('Hello frame world %s!' % self.data)


if __name__ == '__main__':
    parent = Frame(None)
    parent.pack()
    Hello(parent).pack(side = RIGHT)
    Button(parent, text = 'Attach', command = exit).pack(side = LEFT)
    parent.mainloop()
