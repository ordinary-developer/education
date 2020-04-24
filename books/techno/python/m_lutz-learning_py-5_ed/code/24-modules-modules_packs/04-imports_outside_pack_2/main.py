if __name__ == '__main__':
    import string
    print(string)

    try:
        from . import string
    except:
        print('can not load a module')
