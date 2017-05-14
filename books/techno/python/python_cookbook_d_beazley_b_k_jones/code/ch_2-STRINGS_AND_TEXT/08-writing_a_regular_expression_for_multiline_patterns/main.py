def example_1():
    text1 = '/* this is a comment */'
    text2 = '''/* this is a
                  multiline comment */
    '''

    import re
    comment_pattern = re.compile(r'/\*(.*?)\*/')
    print(comment_pattern.findall(text1))
    print(comment_pattern.findall(text2))


def example_2():
    text = '''/* this is a
                  multiline comment */
    '''

    import re
    comment_pattern = re.compile(r'/\*((?:.|\n)*?)\*/')
    print(comment_pattern.findall(text))


def example_3():
    text = '''/* this is a
                  multiline comment */
    '''

    import re
    comment_pattern = re.compile(r'/\*(.*?)\*/', re.DOTALL)
    print(comment_pattern.findall(text))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()

