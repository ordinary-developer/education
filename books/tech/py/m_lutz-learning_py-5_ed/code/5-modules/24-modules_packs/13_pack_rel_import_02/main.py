try:
    import pkg.spam
    assert False
except ModuleNotFoundError:
    assert True
    print('can not load the module')
