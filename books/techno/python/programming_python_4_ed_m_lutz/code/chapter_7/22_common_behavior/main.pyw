from tkinter import *


class HelloButton(Button):

    def __init__(self, parent = None, **config):
        Button.__init__(self, parent, **config)
        self.pack()
        self.config(command = self.callback)

    def callback(self):
        print('Goodbye world ...')
        self.quit()


class MyButton(HelloButton):

    def callback(self):
        print("Ignoring press!...")


if __name__ == '__main__':
    MyButton(None, text = 'Hello subclass world').mainloop()
