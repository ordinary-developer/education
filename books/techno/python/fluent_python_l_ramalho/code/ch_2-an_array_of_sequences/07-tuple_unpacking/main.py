if __name__ == '__main__':
    lax_coordinates = (33.9425, -118.408056)
    latitude, longitude = lax_coordinates
    print(latitude)
    print(longitude)

    b, a = 1, 2
    b, a = a, b
    print(a)
    print(b)

    print(divmod(20, 8))
    t = (20, 8)
    print(divmod(*t))
    quotient, remainder = divmod(*t)
    print(quotient, remainder)

    import os
    _, filename = os.path.split('/home/luciano/.shh/idrsa.pub')
    print(filename)

    a, b, *rest = range(5)
    print(a, b, rest)
    a, b, *rest = range(3)
    print(a, b, rest)
    a, b, *rest = range(2)
    print(a, b, rest)

    a, *body, c, d = range(5)
    print(a, body, c, d)
    *head, b, c, d = range(5)
    print(head, b, c, d)
    
