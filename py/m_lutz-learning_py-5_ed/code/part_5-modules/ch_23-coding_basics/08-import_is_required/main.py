def import_1():
    from m_module import func
    from n_module import func
    func()

def import_2():
    import m_module, n_module
    m_module.func()
    n_module.func()

def import_3():
    from m_module import func as mfunc
    from n_module import func as nfunc
    mfunc(); nfunc()

if __name__ == '__main__':
    import_1()
    import_2()
    import_3()
