if __name__ == '__main__':
    import sys
    from tkinter import *
    widget = Button(None, text = 'hello gui world', command = sys.exit)
    widget.pack()
    widget.mainloop()
