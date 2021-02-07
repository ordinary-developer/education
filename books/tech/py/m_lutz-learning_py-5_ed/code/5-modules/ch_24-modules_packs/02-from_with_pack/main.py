if __name__ == '__main__':
    import dir1.dir2.mod

    try:
        print(dir2.mod)
    except NameError:
        print('can not get dir2.mod directly')

    try:
        print(mod.z)
    except NameError:
        print('can not get mod.z directly')

    from dir1.dir2 import mod
    print(mod.z)

    from dir1.dir2.mod import z
    print(z)

    import dir1.dir2.mod as mod
    print(mod.z)

    from dir1.dir2.mod import z as modz
    print(modz)
