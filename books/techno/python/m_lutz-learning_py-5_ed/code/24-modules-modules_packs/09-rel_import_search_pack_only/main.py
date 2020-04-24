if __name__ == '__main__':
    try:
        import pkg.spam
    except ImportError:
        print('cannot import the module')

