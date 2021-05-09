# the "classes generate multiple instance objects" section
def example_01(): 
    print("example 01 (classes generate multiple instance objects) =>")

    class FirstClass:
        def setdata(self, value):
            self.data = value
        def display(self):
            print(self.data)

    x = FirstClass()
    y = FirstClass()

    x.setdata("King Arthur")
    y.setdata(3.14159)

    x.display()
    y.display()

    x.data = "New value"
    x.display()

    x.anothername = "spam"


# the "classes are customized by inheritance" section
def example_02():
    print("example 02 (classes are customized by inheritance) =>")

    class FirstClass:
        def setdata(self, value):
            self.data = value
        def display(self):
            print(self.data)

    class SecondClass(FirstClass):
        def display(self):
            print('Current value = "%s"' % self.data)

    z = SecondClass()
    z.setdata(42)
    z.display()


# the "classes can intercept Python operators" section
def example_03():
    print("example 03 (classes can intercept Python operators) =>")

    class FirstClass:
        def setdata(self, value):
            self.data = value
        def display(self):
            print(self.data)

    class SecondClass(FirstClass):
        def display(self):
            print('Current value = "%s"' % self.data)

    class ThirdClass(SecondClass):
        def __init__(self, value):
            self.data = value
        def __add__(self, other):
            return ThirdClass(self.data + other)
        def __str__(self):
            return '[ThirdClass: %s]' % self.data
        def mul(self, other):
            self.data *= other

    a = ThirdClass('abc')
    a.display()
    print(a)

    b = a + 'xyz'
    b.display()
    print(b)
    a.mul(3)
    print(a)




if __name__ == '__main__':
    example_01()
    example_02()
    example_03()
