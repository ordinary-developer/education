# the "step 1: making instances" subchapter
def example_01():
    print('example 01 (the "step 1: making instances" subchapter) =>')
    class Person:
        def __init__(self, name, job = None, pay = 0):
            self.name = name
            self.job = job
            self.pay = pay

    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob.name, bob.pay)
    print(sue.name, sue.pay)
    print('\n')


# the "step 2: adding behavior methods" subchapter
def example_02():
    print('example 01 (the "step 2: adding behavior methods" subchapter) =>')

    name = 'Bob Smith'
    print(name.split())
    print(name.split()[-1])

    pay = 100000
    pay *= 1.10
    print('%.2f' % pay)

    class Person:
        def __init__(self, name, job = None, pay = 0):
            self.name = name
            self.job = job
            self.pay = pay
    
    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob.name, bob.pay)
    print(sue.name, sue.pay)
    print(bob.name.split()[-1])
    sue.pay *= 1.10
    print('%2.f' % sue.pay)

    class Person:
        def __init__(self, name, job = None, pay = 0):
            self.name = name
            self.job = job
            self.pay = pay

        def lastName(self):
            return self.name.split()[-1]
        
        def giveRaise(self, percent):
            self.pay = int(self.pay * (1 + percent))

    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob.name, bob.pay)
    print(sue.name, sue.pay)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.10)
    print(sue.pay)
    print('\n')


# the "step 3: operator overloading" subchapter
def example_03():
    print('example 03 (the "step 3: operator overloading" subchapter) =>')

    class Person:
        def __init__(self, name, job = None, pay = 0):
            self.name = name
            self.job = job
            self.pay = pay

        def lastName(self):
            return self.name.split()[-1]

        def giveRaise(self, percent):
            self.pay = int(self.pay * (1 + percent))

        def __repr__(self):
            return '[Person: %s, %s]' % (self.name, self.pay)

    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob)
    print(sue)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.10)
    print(sue)
    print('\n')


if __name__ == '__main__':
    example_01()
    example_02()
    example_03()
