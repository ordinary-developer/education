if __name__ == '__main__':
    rec = {'name': {'first': 'Bob', 'last': 'Smith'},
           'jobs': ['dev', 'mgr'],
           'age': 40.5 }

    print(rec['name'])
    print(rec['name']['last'])
    print(rec['jobs'])
    print(rec['jobs'][-1])

    rec['jobs'].append('janitor')
    print(rec)
