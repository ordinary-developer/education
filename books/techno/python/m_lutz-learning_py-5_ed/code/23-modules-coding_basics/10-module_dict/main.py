if __name__ == '__main__':
    import module1
    
    print(list(module1.__dict__.keys()))

    print(list(name for name in module1.__dict__.keys() if not name.startswith('__')))
    print(list(name for name in module1.__dict__.keys() if name.startswith('__')))

    print(module1.name, module1.__dict__['name'])
