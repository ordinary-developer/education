class C2:
    pass

class C3:
    pass

class C1(C2, C3):
    def __init__(self, who):
        self.name = who

i1 = C1('bob')
i2 = C1('sue')
print(i1.name)
print(i2.name)
