if __name__ == '__main__':
    from tkinter import *
    root = Tk()
    widget = Label(root)
    widget.configure(text = 'hello gui world')
    widget.pack(side = TOP, expand = YES, fill = BOTH)
    root.title('main.pyw')
    root.mainloop()
