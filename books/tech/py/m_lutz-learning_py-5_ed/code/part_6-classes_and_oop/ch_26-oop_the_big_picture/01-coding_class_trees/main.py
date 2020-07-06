def example_01():
    class C2:
        pass

    class C3:
        pass

    class C1(C2, C3):
        pass

    i1 = C1()
    i2 = C1()
    print(i1)
    print(i2)

def example_02():
    class C2:
        pass

    class C3:
        pass
    
    class C1(C2, C3):
        def setname(self, who):
            self.name =  who
    
    i1 = C1()
    i2 = C1()
    i1.setname('bob')
    i2.setname('sue')
    print(i1.name)
    print(i2.name)


if __name__ == '__main__':
    examples = [example_01, example_02]
    for i in range(0, len(examples)):
        print('example [{0}] =>'.format(i + 1))
        examples[i]()
        print('')
