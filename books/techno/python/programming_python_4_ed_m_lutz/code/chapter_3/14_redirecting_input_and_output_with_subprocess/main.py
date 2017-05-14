if __name__ == '__main__':  
    import os
    p1 = os.popen('~/shortucts/python writer.py', 'r')
    p2 = os.popen('~/shortucts/python reader.py', 'w')
    print(p2.write(p1.read()))
    print(p2.close())

