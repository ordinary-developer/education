from urllib.request import urlopen
conn = urlopen('http://localhost/cgi-bin/cgi101.py?user=Sue+Smith')
reply = conn.read()
print(reply) 

print(urlopen('http://localhost/cgi-bin/cgi101.py').read())

print(urlopen('http://localhost/cgi-bin/cgi101.py?user=Bob').read())

