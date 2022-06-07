try:
    import spam
    assert False
except ImportError:
    print('import err')
