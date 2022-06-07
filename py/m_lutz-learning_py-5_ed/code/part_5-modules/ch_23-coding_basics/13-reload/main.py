if __name__ == '__main__':
    # import
    import changer
    changer.printer()

    # deprecated reload
    from imp import reload as depr_reload
    depr_reload(changer)
    changer.printer()

    # "normal" reload
    from importlib import reload
    reload(changer)
    changer.printer()
