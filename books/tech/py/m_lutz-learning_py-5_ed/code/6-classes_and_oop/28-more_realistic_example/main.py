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


if __name__ == '__main__':
    example_01()
