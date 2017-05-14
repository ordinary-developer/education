from tkinter import *


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


class HelloContainer(Frame):

    def __init__(self, parent = None):
        Frame.__init__(self, parent)
        self.pack()
        self.make_widgets()

    def make_widgets(self):
        Hello(self).pack(side = RIGHT)
        Button(self, text = 'Attach', command = self.quit).pack(side = LEFT)


if __name__ == '__main__':
    HelloContainer().mainloop()
