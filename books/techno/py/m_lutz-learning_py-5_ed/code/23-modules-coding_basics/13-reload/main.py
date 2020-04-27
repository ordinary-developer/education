if __name__ == '__main__':
    import changer
    changer.printer()

    from imp import reload
    reload(changer)
    changer.printer()
