if __name__ == '__main__':
    from tkinter import *
    options = {'text': 'hello gui world'}
    layout = {'side': 'top'}
    Label(None, **options).pack(**layout)
