if __name__ == '__main__':
    from tkinter import *
    root = Tk()
    Button(root, text = 'press', command = root.quit).pack(
            side = LEFT, expand = YES, fill = BOTH)
    root.mainloop()
