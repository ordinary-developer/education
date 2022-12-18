if __name__ == '__main__':
    from small import x

    import small
    print(small.x)
    small.x = 42
    
    print(small.x)
    print(x)
