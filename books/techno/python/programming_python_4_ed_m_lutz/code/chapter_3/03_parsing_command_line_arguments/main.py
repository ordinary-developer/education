def get_options(arguments):
    options = {}

    while arguments:
        if arguments[0][0] == '-':
            options[arguments[0]] = arguments[1]
            arguments = arguments[2:]
        else:
            arguments = arguments[1:]

    return options


if __name__ == '__main__':
    import sys

    arguments = get_options(sys.argv)
    if '-i' in arguments:
        print(arguments['-i'])
    print(arguments)
    
