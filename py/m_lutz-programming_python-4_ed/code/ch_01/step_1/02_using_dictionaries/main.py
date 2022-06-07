if __name__ == '__main__':
    # [Other ways to make dictionaries] region
    bob = {'name': 'Bob Smith', 'age': 42, 'pay': 30000, 'job': 'dev'}
    sue = {'name': 'Sue Jones', 'age': 45, 'pay': 40000, 'job': 'hwd'}
    
    print(bob['name'], sue['pay'])
    print(bob['name'].split()[-1])
    sue['pay'] *= 1.10
    print(sue['pay'])

    bob = dict(name = 'Bob Smith', age = 42, pay = 30000, job = 'dev')
    sue = dict(name = 'Sue Jones', age = 45, pay = 40000, job = 'hdw')
    print(bob)
    print(sue)

    sue = {}
    sue['name'] = 'Sue Jones'
    sue['age'] = 45
    sue['pay'] = 40000
    sue['job'] = 'hdw'
    print(sue)

    names = ['name', 'age', 'pay', 'job']
    values = ['Sue Jones', 45, 40000, 'hdw']
    aList = zip(names, values)
    print(list(zip(names, values)))
    sue = dict(zip(names, values))
    print(sue)

    fields = ('name', 'age', 'job', 'pay')
    record = dict.fromkeys(fields, '?')
    print(record)

    print('-' * 25)
    # endregion


    # [List of dictionaries] region
    print(bob)
    print(sue)

    people = [bob, sue]
    for person in people:
        print(person['name'], person['pay'], sep = ', ')

    for person in people:
        if person['name'] == 'Sue Jones':
            print(person['pay'])

    names = [person['name'] for person in people]
    print(names)

    print(list(map((lambda x: x['name']), people)))
    
    print(sum(person['pay'] for person in people))

    print([rec['name'] for rec in people if rec['age'] >= 45])
    print(
      [(rec['age'] ** 2 if rec['age'] >= 45 else rec['age']) for rec in people])
    G = (rec['name'] for rec in people if rec['age'] >= 45)
    print(next(G))
    G = (
      (rec['age'] ** 2 if rec['age'] >= 45 else rec['age']) for rec in people) 
    print(G.__next__())

    for person in people:
        print(person['name'].split()[-1])
        person['pay'] *= 1.10
    for person in people: print(person['pay'])

    print('-' * 25)
    # endregion


    # [Nested structures] region
    bob2 = {'name': {'first': 'Bob', 'last': 'Smith'},
            'age': 42,
            'job': ['software', 'writing'],
            'pay': (40000, 50000) }

    print(bob2['name'])
    print(bob2['name']['last'])
    print(bob2['pay'][1])

    for job in bob2['job']: print(job)

    print(bob2['job'][-1])
    print(bob2['job'].append('janitor'))
    print(bob2)

    print('-' * 25)
    # endregion


    # [Dictionaries of dictionaries] region
    bob = dict(name = 'Bob Smith', age = 42, pay = 30000, job = 'dev')
    sue = dict(name = 'Sue Jones', age = 45, pay = 40000, job = 'hdw')
    print(bob)

    db = {}
    db['bob'] = bob
    db['sue'] = sue

    print(db['bob']['name'])
    db['sue']['pay'] = 50000
    print(db['sue']['pay'])

    print(db)
    import pprint
    pprint.pprint(db)

    for key in db:
        print(key, '=>', db[key]['name'])
    for key in db:
        print(key, '=>', db[key]['pay'])

    for key in db:
        print(db[key]['name'].split()[-1])
        db[key]['pay'] *= 1.10
    for record in db.values(): 
        print(record['pay'])

    x = [db[key]['name'] for key in db]
    print(x)

    x = [rec['name'] for rec in db.values()]
    print(x)

    db['tom'] = dict(name = 'Tom', age = 50, job = None, pay = 0)

    print(db['tom'])
    print(db['tom']['name'])

    print(list(db.keys()))
    print(len(db))

    print([rec['age'] for rec in db.values()])
    print([rec['name'] for rec in db.values() if rec['age'] >= 45])
    # endregion




