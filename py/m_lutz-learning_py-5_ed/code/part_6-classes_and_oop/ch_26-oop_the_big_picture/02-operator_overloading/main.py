class C2:
    pass

class C3:
    pass

class C1(C2, C3):
    def __init__(self, who):
        self.name = who
        
i1 = C1('bob')
assert i1.name == 'bob'
i2 = C1('sue')
assert i2.name == 'sue'
