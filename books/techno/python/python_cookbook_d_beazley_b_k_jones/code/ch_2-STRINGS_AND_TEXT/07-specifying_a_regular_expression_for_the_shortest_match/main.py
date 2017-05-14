def example_1():
    text1 = 'Computer says "no."'
    text2 = 'Computer says "no." Phone says "yes."'

    import re
    pattern = re.compile(r'\"(.*)\"')
    print(pattern.findall(text1))
    print(pattern.findall(text2))
    

def example_2():
    text = 'Computer says "no." Phone says "yes."'

    import re
    pattern = re.compile(r'\"(.*?)\"')
    print(pattern.findall(text))


if __name__ == '__main__':
    example_1()
    example_2()
    
