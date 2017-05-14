# interactive updates

import shelve
from person import Person
fieldnames = ('name', 'age', 'job', 'pay')

db = shelve.open('class-shelve')

while True:
    key = input('\nKey? => ')

    if not key:
        break

    if key in db:
        record = db[key]
    else:
        record = Person(name = '?', age = '?')
    for field in fieldnames:
        cur_value = getattr(record, field)
        new_value = input('\t[{}]={}\n\t\tnew? =>'.format(field, cur_value))
        if new_value:
            setattr(record, field, eval(new_value))
    db[key] = record
db.close(
