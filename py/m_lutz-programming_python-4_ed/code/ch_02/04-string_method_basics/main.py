if __name__ == '__main__':  
    
    mystr = 'xxxSPAMxxx'
    print(mystr.find('SPAM'))
    mystr = 'xxxaaxxxaa'
    print(mystr.replace('aa', 'SPAM'))

    mystr = 'xxxSPAMxxx'
    print('SPAM' in mystr)
    print('Ni' in mystr)
    print(mystr.find('Ni'))
    mystr = '\t  Ni\n'
    print(mystr.strip())
    print(mystr.rstrip())

    mystr = 'SHRUBBERY'
    print(mystr.lower())
    print(mystr.isalpha())
    print(mystr.isdigit())
    import string
    print(string.ascii_lowercase) 
    print(string.whitespace)

    print('-' * 25)

    # ----------
    mystr = 'aaa,bbb,ccc'
    print(mystr.split(','))
    mystr = 'a  b\nc\nd'
    print(mystr.split())
    delim = 'NI'
    print(delim.join(['aaa', 'bbb', 'ccc']))
    print(' '.join(['A', 'dead', 'parrot']))
    chars = list('lorreta')
    print(chars)
    chars.append('!')
    print(''.join(chars))

    mystr = 'xxxaaxxaa'
    print('SPAM'.join(mystr.split('aa')))

    print(int("42"))
    print(eval("42"))
    print(str(42))
    print(repr(42))
    print(42)
    print("%d" % 42)
    print('{:d}'.format(42))
    print("42" + str(1))
    print(int("42") + 1)

    # --------------
    mystr = 'aaa,bbb,ccc'
    print(mystr.split(','))
    mystr = 'a b\nc\nd'
    print(mystr.split())
    delim = 'NI'
    print(delim.join(['aaa', 'bbb', 'ccc']))
    print(' '.join(['A', 'dead', 'parrot']))
    chars = list('Lorreta')
    print(chars)
    chars.append('!')
    print(''.join(chars))

    mystr = 'xxxaaxxxaa'
    print('SPAM'.join(mystr.split('aa')))
    print(int("42"))
    print(eval("42"))
    print(str(42))
    print(repr(42))
    print("%d" % 42)
    print('{:d}'.format(42))
    print("42" + str(1))
    print(int("42") + 1)
