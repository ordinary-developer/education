from person_start import Person


bob = Person('Bob Smith', 42)
sue = Person('Sue Jones', 45, 40000)

people = [bob, sue]
for person in people:
    print(person.name, person.pay)

x = [(person.name, person.pay) for person in people]
print(x)

x = [rec.name for rec in people if rec.age >= 45]
print(x)

x = [(rec.age ** 2 if rec.age >= 45 else rec.age) for rec in people]
print(x)


from person import Person
from manager import Manager

bob = Person(name = 'Bob Smith', age = 42, pay = 10000)
sue = Person(name = 'Sue Jones', age = 45, pay = 20000)
tom = Manager(name = 'Tom Doe', age = 55, pay = 30000)

db = [bob, sue, tom]

for obj in db:
    obj.giveRaise(.10)

for obj in db:
    print(obj.lastName(), '=>', obj.pay)

