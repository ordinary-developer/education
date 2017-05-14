"""
a Quit button that verifies exit requests;
to reuse, attach an instance to other GUIs, and re-pack as desired
"""


from tkinter import *
from tkinter.messagebox import askokcancel


class Quitter(Frame):

    def __init__(self, parent = None):
        Frame.__init__(self, parent)
        self.pack()
        widget = Button(self, text = 'Quit', command = self.quit)
        widget.pack(side = LEFT, expand = YES, fill = BOTH)

    def quit(self):
        answer = askokcancel('Verify exit', "Really quit?")
        if answer:
            Frame.quit(self)


if __name__ == '__main__':
    Quitter().mainloop()
