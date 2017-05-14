if __name__ == '__main__':
    import subprocess

    subprocess.call('ls')
    subprocess.call('ls', shell = True)
    # doesn't work
    # subprocess.call('cmd /C "type helloshell.py"')
    # subprocess.call('type helloshell.py', shell = True)
    print('-' * 25)

    pipe = subprocess.Popen('ls', stdout = subprocess.PIPE)
    print(pipe.communicate())
    print(pipe.returncode)
    print('-' * 25)

    pipe = subprocess.Popen('ls', stdout = subprocess.PIPE)
    print(pipe.stdout.read())
    print(pipe.wait())
    print('-' * 25)

    from subprocess import Popen, PIPE
    print(Popen('ls', stdout = PIPE).communicate()[0])
    import os
    print(os.popen('ls').read())
