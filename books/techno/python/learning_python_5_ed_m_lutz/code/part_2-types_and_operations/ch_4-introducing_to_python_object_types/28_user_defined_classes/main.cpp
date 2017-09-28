class Worker:
    def __init__(self, name, pay):
        self.name = name
        self.pay = pay

    def lastName(self):
        return self.name.split()[-1]

    def giveRaise(self, precent):
        self.pay *= (1.0 + percent)


if __name__ == '__main__':
    bob = Worker('Bob Smith', 50000)
    sue = Worker('Sue Jones', 60000)
    print(bob.lastName())
    print(sue.lastName())
    sue.giveRaise(.10)
    print(sue.pay)
