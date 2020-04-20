if __name__ == '__main__':
    from small import x, y
    x = 42
    y[0] = 42
    
    import small
    print(small.x)
    print(small.y)
