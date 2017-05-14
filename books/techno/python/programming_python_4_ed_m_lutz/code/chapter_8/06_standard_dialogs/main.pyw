from tkinter import *
from tkinter.messagebox import *


def callback():
    if askyesno('Verify', 'Do you really want to quit?'):
        showwarning('Yes', 'Quit not yet implemented')
    else:
        showinfo('No', 'Quit has been cancelled')


if __name__ == '__main__':
    error_message = 'Sorry, no Spam allowed!'
    Button(text = 'Quit', command = callback).pack(fill = X)
    Button(text = 'Spam', 
            command = (lambda: showerror('Spam', error_message))).pack(fill = X)
    mainloop()
