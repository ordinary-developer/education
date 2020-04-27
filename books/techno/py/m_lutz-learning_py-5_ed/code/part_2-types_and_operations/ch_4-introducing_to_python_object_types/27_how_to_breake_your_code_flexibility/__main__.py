if __name__ == '__main__':
    L = [1, 2, 3]

    print(type(L))
    print(type(type(L)))

    if type(L) == type([]):
        print('yes')
    if type(L) == list:
        print('yes')
    if isinstance(L, list):
        print('yes')
