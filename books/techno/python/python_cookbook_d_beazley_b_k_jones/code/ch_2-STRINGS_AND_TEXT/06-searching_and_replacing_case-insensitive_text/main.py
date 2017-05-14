def example_1():
    text = 'UPPER PYTHON, lower python, Mixed Python'

    import re
    print(re.findall('python', text, re.IGNORECASE))
    print(re.sub('python', 'snake', text, re.IGNORECASE))


def example_2():
    text = 'UPPER PYTHON, lower python, Mixed Python'

    def matchcase(word):
        def replace(m):
            text = m.group()
            if text.isupper():
                return word.upper()
            elif text.islower():
                return word.lower()
            elif text[0].isupper():
                return word.capitalize()
            else:
                return word
        return replace

    import re
    print(re.sub('python',
                 matchcase('snake'),
                 text,
                 flags = re.IGNORECASE))
                

if __name__ == '__main__':
    example_1()
    example_2()
