if __name__ == '__main__':
    bob = ['Bob Smith', 42, 30000, 'software']
    sue = ['Sue Jones', 45, 40000, 'hardware']

    print(bob[0], sue[2])
    print(bob[0].split()[-1])

    sue[2] *= 1.25
    print(sue)

    print('-' * 25)


    # [A datbase list] - region
    people = [bob, sue]
    for person in people:
        print(person)

    print(people[1][0])

    for person in people:
        print(person[0].split()[-1])
        person[2] *= 1.2

    for person in people:
        print(person[2])

    pays = [person[2] for person in people]
    print(pays)

    pays = map((lambda x: x[2]), people)
    print(list(pays))

    print(sum(person[2] for person in people))
    
    people.append(['Tom', 50, 0, None])
    print(len(people))
    print(people[-1][0])

    print('-' * 25)


    NAME, AGE, PAY = range(3)
    bob = ['Bob Smith', 42, 10000]
    print(bob[NAME])
    print(PAY, bob[PAY])

    bob = [['name', 'Bob Smith'], ['age', 42], ['pay', 10000]]
    sue = [['name', 'Sue Jones'], ['age', 45], ['pay', 20000]]
    people = [bob, sue]

    for person in people:
        print(person[0][1], person[2][1])

    print([person[0][1] for person in people])

    for person in people:
        print(person[0][1].split()[-1])
        person[2][1] *= 1.10
    for person in people:
        print(person[2])

    print('-' * 25)


    for person in people:
        for (name, value) in person:
            if name == 'name':
                print(value)

    def field(record, label):
        for (fname, fvalue) in record:
            if fname == label:
                return value

    field(bob, 'name')
    field(sue, 'pay')

    for rec in people:
        print(field(rec, 'age'))
