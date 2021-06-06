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


# the "step 4: customizing behavior by subclassing" subchapter
def example_04():
    print('example 04 (the "step 4: customizing behavior by subclassing" subchapter) =>')

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

    class Manager(Person):
        def giveRaise(self, percent, bonus = .10):
            Person.giveRaise(self, percent + bonus)

    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob)
    print(sue)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.10)
    print(sue)
    tom = Manager('Tom Jones', 'mgr', 50000)
    tom.giveRaise(.10)
    print(tom.lastName())
    print(tom)

    print('--all three--')
    for obj in (bob, sue, tom):
        obj.giveRaise(.10)
        print(obj)
    print('\n')


# the "step 5: customizing constructors" subchapter
def example_05():
    print('example 05 (the "step 5: customizing constructors" subchapter) =>')

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

    class Manager(Person):
        def __init__(self, name, pay):
            Person.__init__(self, name, 'mgr', pay)
        
        def giveRaise(self, percent, bonus = .10):
            Person.giveRaise(self, percent + bonus)

    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    print(bob)
    print(sue)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.10)
    print(sue)
    tom = Manager('Tom Jones', 50000)
    tom.giveRaise(.10)
    print(tom.lastName())
    print(tom)

    class Manager:
        def __init__(self, name, pay):
            self.person = Person(name, 'mgr', pay)

        def giveRaise(self, percent, bonus = .10):
            self.person.giveRaise(percent + bonus)

        def __getattr__(self, attr):
            return getattr(self.person, attr)

        def __repr__(self):
            return str(self.person)

    tom = Manager('Tom Jones', 50000)       
    tom.giveRaise(.10)
    print(tom.lastName())
    print(tom)
    print('\n')

    class Department:
        def __init__(self, *args):
            self.members = list(args)
        def addMember(self, person):
            self.members.append(person)
        def giveRaises(self, percent):
            for person in self.members:
                person.giveRaise(percent)
        def showAll(self):
            for person in self.members:
                print(person)

    bob = Person('Bob Smith') 
    sue = Person('Sue Jones', job = 'dev', pay = 100000)
    tom = Manager('Tom Jones', 50000)

    development = Department(bob, sue)
    development.addMember(tom)
    development.giveRaises(.10)
    development.showAll()


if __name__ == '__main__':
    example_01()
    example_02()
    example_03()
    example_04()
    example_05()
