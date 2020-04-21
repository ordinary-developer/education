if __name__ == '__main__':
    x = 1
    import module1

    print(x, end = ' ')          # my global x
    print(module1.x, end = ' ')  # module1's x
    print(module1.module2.x)     # nested module2' x
