if __name__ == '__main__':
    try:
        import pkg.spam
        assert False
    except ModuleNotFoundError:
        print('module not found error')
