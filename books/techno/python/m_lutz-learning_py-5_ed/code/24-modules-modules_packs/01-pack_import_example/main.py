if __name__ == '__main__':
    import dir1.dir2.mod
    import dir1.dir2.mod

    from imp import reload
    print(reload(dir1))

    print(reload(dir1.dir2))

    print(dir1)
    print(dir1.dir2)
    print(dir1.dir2.mod)

    print(dir1.x)
    print(dir1.dir2.y)
    print(dir1.dir2.mod.z)
