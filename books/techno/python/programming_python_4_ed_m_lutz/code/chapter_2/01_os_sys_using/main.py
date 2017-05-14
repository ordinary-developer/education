if __name__ == '__main__':
    import sys, os
    print(len(dir(sys)))
    print(len(dir(os)))
    print(len(dir(os.path)))
    
    print(dir(sys))
    print(sys.__doc__)
    print(help(sys))

