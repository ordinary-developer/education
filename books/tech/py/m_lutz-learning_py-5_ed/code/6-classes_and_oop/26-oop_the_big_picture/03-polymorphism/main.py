class Employee:
    def method(self):
        print('employee.method')

class Engineer(Employee):
    def method(self):
        print('engineer.method')

bob = Employee()
sue = Employee()
tom = Engineer()

company = [bob, sue, tom]
for employee in company:
    employee.method()
