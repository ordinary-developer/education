if __name__ == '__main__':
    import re
    match = re.match('Hello[ \t]*(.*)world', 'Hello   Python world')
    print(match.groups(1))
    print('-' * 25)

    match = re.match('[/:](.*)[/:](.*)[/:](.*)', '/usr/home:lumberjack')
    print(match.groups())
    print(re.split('[/:]', '/usr/home/lumberjack'))
