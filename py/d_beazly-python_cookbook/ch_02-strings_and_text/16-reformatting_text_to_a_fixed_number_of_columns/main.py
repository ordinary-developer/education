def example_1():
    s = "Look into my eyes, look into my eyes, the eyes, \
    the eyes, not around the eyes, don't look around the eyes, \
    look into my eyes, you're under."

    import textwrap
    print(textwrap.fill(s, 70))
    print(textwrap.fill(s, 40))
    print(textwrap.fill(s, 40, initial_indent = '     '))
    print(textwrap.fill(s, 40, subsequent_indent = '   '))


def example_2():
    import os
    print(os.get_terminal_size().columns)
    

if __name__ == '__main__':
    example_1()
    print('-' * 75)

    example_2()
    print('-' * 75)

