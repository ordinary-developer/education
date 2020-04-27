def load_first():
    from module_name import name1, name2

def load_second():
    import module_name
    name1 = module_name.name1
    name2 = module_name.name2
    del module_name

if __name__ == '__main__':
    load_first()
    load_second()
