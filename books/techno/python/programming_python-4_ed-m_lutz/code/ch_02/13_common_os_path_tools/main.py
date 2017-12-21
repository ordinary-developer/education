if __name__ == '__main__':
    import os

    print(os.path.isdir(r'/home/ivan'), os.path.isfile(r'/home/ivan'))
    print(os.path.isdir(r'/etc/network/interfaces'),
                os.path.isfile(r'/etc/network/interfaces'))
    print(os.path.isdir('nonesuch'), os.path.isfile('nonesuch'))
    print(os.path.exists(r'/home/ivan'))
    print(os.path.exists(r'/etc/network/interfaces'))
    print(os.path.getsize(r'/etc/network/interfaces'))

    print('-' * 25)

    print(os.path.split(r'C:\temp\data.txt'))
    print(os.path.join(r'C:\temp', 'output.txt'))
    name = '/home/lutz/temp/data.txt'
    print(os.path.dirname(name))
    print(os.path.basename(name))
    print(os.path.splitext(r'C:\PP4thED\Examples\PP4E\PyDemos.pyw'))
    print(os.path.splitext('/home/ivan/work/text.txt'))

    print('-' * 25)

    print(os.sep)
    pathname = r'/home/ivan/work/python.py'
    print(os.path.split(pathname))
    print(pathname.split(os.sep))
    print(os.sep.join(pathname.split(os.sep)))
    print(os.path.join(*pathname.split(os.sep)))

    print('-' * 25)

    mixed = r'C:\\temp\\public/files/index.html'
    print(os.path.normpath(mixed))
    print(os.path.normpath(r'C:\temp\\sub\.\file.ext'))

    print('-' * 25)

    os.chdir(r'/home/ivan')
    print(os.getcwd())
    print(os.path.abspath(''))
    print(os.path.abspath('work'))
    print(os.path.abspath('.'))
    print(os.path.abspath('..'))
    print(os.path.abspath(r'/home/ivan'))
    print(os.path.abspath(r'/etc/network/interfaces'))
