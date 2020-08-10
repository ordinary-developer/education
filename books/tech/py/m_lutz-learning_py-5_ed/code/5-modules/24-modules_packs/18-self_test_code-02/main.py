try:
    import dualpkg.m2
    assert False
except ModuleNotFoundError:
    print('module not found')
