"""
various specialied string display formatting utilities
"""

def commas(num):
    """
    Format positive integer-like `num`
    for display with commas between digit groupings: "xxx,yyy,zzz".
    """
    digits = str(num)
    assert(digits.isdigit())
    result = ''
    while digits:
        digits, last3 = digits[:-3], digits[-3:]
        result = (last3 + ',' + result) if result else last3
    return result

def money(num, numwidth = 0, currency = '$'):
    """
    Format number `num` for display with commas, 2 decimal digits,
    leading $ and sign, and optional padding: "$   -xxx,yyy.zz".
    `numwidth` = 0 for space padding, `curreny` = '' to omit symbol,
    and non-ASCII for others (e.g., pound = u'\xa3', or u'\u00a3').
    """
    sign = '-' if num < 0 else ''
    num = abs(num)
    whole = commas(int(num))
    fract = ('%.2f' % num)[-2:]
    number = '%s%s.%s' % (sign, whole, fract)
    return '%s%*s' % (currency, numwidth, number)

if __name__ == '__main__':
    def selftest():
        tests = 0, 1
        tests += 12, 123, 1234, 12345, 123456, 1234567
        tests += 2 ** 32, 2 ** 100
        for test in tests:
            print(commas(test))
            
        tests = 0, 1, -1, 1.23, 1., 1.2, 3.14159
        tests += 12.34, 12.344, 12.345, 12.346
        tests += 2 ** 32, (2 ** 32 + .2345)
        tests += 1.2345, 1.2, 0.2345
        tests += -1.2345, -1.2, -0.2345
        tests += -(2 ** 32), -(2 ** 32 + .2345)
        tests += (2 ** 100), -(2 ** 100)
        for test in tests:
            print('%s [%s]' % (money(test, 17), test))
            
    import sys
    if len(sys.argv) == 1:
        selftest()
    else:
        print(money(float(sys.argv[1]), int(sys.argv[2])))
