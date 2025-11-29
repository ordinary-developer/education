if __name__ == '__main__':
    from more import more
    import sys
    more(sys.__doc__, 5)

    more(open('more.py').read(), 10)
