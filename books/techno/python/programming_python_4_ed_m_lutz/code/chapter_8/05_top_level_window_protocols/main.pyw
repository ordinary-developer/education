from tkinter import *


if __name__ == '__main__':
    root = Tk()

    trees = [('The Larch!', 'light blue'),
             ('The Pine!', 'light green'),
             ('The Giant Redwood!', 'red')]

    for (tree, color) in trees:
        win = Toplevel(root)
        win.title('Sing...')
        win.protocol('WM_DELETE_WINDOW', lambda: None)

        msg = Button(win, text = tree, command = win.destroy)
        msg.pack(expand = YES, fill = BOTH)
        msg.config(padx = 10, pady = 10, bd = 10, relief = RAISED)
        msg.config(bg = 'black', fg = color, font = ('times', 30, 'bold'))

    root.title('Lumberjack demo')
    Label(root, text = 'Main window', width = 30).pack()
    Button(root, text = 'Quit All', command = root.quit).pack()
    root.mainloop()
