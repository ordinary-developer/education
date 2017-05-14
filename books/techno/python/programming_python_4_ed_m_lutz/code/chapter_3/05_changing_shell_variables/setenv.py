import os

print('setenv...', end = ' ')
print(os.environ['USER'])

os.environ['USER'] = 'Brian'
os.system('/home/ivan/shortcuts/python echoenv.py')

os.environ['USER'] = 'Arthur'
os.system('/home/ivan/shortcuts/python echoenv.py')

os.environ['USER'] = input('?')
print(os.popen('/home/ivan/shortcuts/python echoenv.py').read())
