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
            
    x = FirstClass()
    x.setdata(17)

    z = SecondClass()
    z.setdata(42)
    z.display()
    
    x.display()


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


# the "the world's simplest Python class" section
def example_04():
    print("example 04 (the world's simplest Python class) =>")

    class rec:
        pass

    rec.name = 'Bob'
    rec.age = 41
    print(rec.name)

    x = rec()
    y = rec()
    print(x.name, y.name)
    x.name = 'Sue'
    print(rec.name, x.name, y.name)

    print(list(rec.__dict__.keys()))
    print(list(name for name in rec.__dict__ if not name.startswith('__')))
    print(list(x.__dict__.keys()))
    print(list(y.__dict__.keys()))

    print(x.name, x.__dict__['name'])
    print(x.age)

    print(x.__class__)
    print(rec.__bases__)

    def uppername(obj):
        return obj.name.upper()

    print(uppername(x))
    rec.method = uppername
    print(x.method())
    print(y.method())
    print(rec.method(x))


# the "records revisited" section
def example_05():
    print("example 05 (records revisited: classes versus dictionaries) =>")

    rec = ('Bob', 40.5, ['dev', 'mgr'])
    print(rec[0])

    rec = {}
    rec['name'] = 'Bob'
    rec['age'] = 40.5
    rec['jobs'] = ['dev', 'mgr']
    print(rec['name'])

    class rec:
        pass

    rec.name = 'Bob'
    rec.age = 40.5
    rec.jobs = ['dev', 'mgr']
    print(rec.name)

    class rec:
        pass

    pers1 = rec()
    pers1.name = 'Bob'
    pers1.jobs = ['dev', 'mgr']
    pers1.age = 40.5

    pers2 = rec()
    pers2.name = 'Sue'
    pers2.jobs = ['dev', 'cto']

    print(pers1.name, pers2.name)

    class Person:
        def __init__(self, name, jobs, age = None):
            self.name = name
            self.jobs = jobs
            self.age = age
        def info(self):
            return (self.name, self.jobs)                        

    rec1 = Person('Bob', ['dev', 'mgr'], 40.5)
    rec2 = Person('Sue', ['dev', 'cto'])
    print(rec1.jobs, rec2.info())

    rec = dict(name = 'Bob', age = 40.5, jobs = ['dev', 'mgr'])
    print(rec)

    rec = {'name': 'Bob', 'age': 40.5, 'jobs': ['dev', 'mgr']}
    print(rec)

    from collections import namedtuple
    Rec = namedtuple('Rec', ['name', 'age', 'jobs'])
    rec = Rec('Bob', 40.5, ['dev', 'mgr'])
    print(rec)


if __name__ == '__main__':
    example_01()
    example_02()
    example_03()
    example_04()
    example_05()
