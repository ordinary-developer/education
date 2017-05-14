if __name__ == '__main__':
    import os

    if 'TEMP' in os.environ:
        print(os.environ['TEMP'])
    os.environ['TEMP'] = r'c:\temp'
    print(os.environ['TEMP'])
