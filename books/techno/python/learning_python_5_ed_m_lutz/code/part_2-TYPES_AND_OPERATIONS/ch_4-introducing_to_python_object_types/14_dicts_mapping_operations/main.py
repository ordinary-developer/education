if __name__ == '__main__':
    d = {'food': 'Spam', 'quantity': 4, 'color': 'pink'}
    print(d['food'])
    d['quantity'] += 1
    print(d)

    d = {}
    d['name'] = 'bob'
    d['job'] = 'dev'
    d['age'] = 40
    print(d)
    print(d['name'])

    bob1 = dict(name = 'bob', job = 'dev', age = 40)
    print(bob1)
    bob2 = dict(zip(['name', 'job', 'age'], ['bob', 'dev', 40]))
    print(bob2)

