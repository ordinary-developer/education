from tkinter import *

def greeting():
    print('Hello stdout world!...')


if __name__ == '__main__':
    win = Frame()
    win.pack()
    Label(win, text = 'Hello container world').pack(side = TOP)
    Button(win, text = 'Hello', command = greeting).pack(side = LEFT)
    Button(win, text = 'Quit', command = win.quit).pack(side = RIGHT)
    win.mainloop()
