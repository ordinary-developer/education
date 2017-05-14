if __name__ == "__main__":
    s = 'A\tB\tC'
    print(len(s))
    print(ord('\n'))
    s = 'A\0B\0C'
    print(len(s))
    print(s)
    print('-' * 50)

    msg = """
    aaaaaaaaa
    bbbbbb''''bbbbb
    ccccccc
    """
    print(msg)
