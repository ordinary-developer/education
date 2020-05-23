from formats import money

x = 54321.987

print(money(x), money(x, 0, ''))
print(money(x, currency = u'\xa3'), money(x, currency = u'\u00a5'))
print(money(x, currency = b'\xa3'.decode('latin-1')))

print(money(x, currency = u'\u20ac'), money(x, 0, b'\xa4'.decode('iso-8859-15')))
print(money(x, currency = b'\xa4'.decode('latin-1')))
