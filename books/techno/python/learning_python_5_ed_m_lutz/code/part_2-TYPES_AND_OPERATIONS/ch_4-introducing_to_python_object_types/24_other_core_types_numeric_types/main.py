if __name__ == '__main__':
    block_delimiter = 25 * '-'

    print(1/3)
    print((2/3  + 1/2))
    print(block_delimiter)

    import decimal
    d = decimal.Decimal('3.141')
    print(d + 1)
    print(block_delimiter)

    import decimal
    decimal.getcontext().prec = 2
    d = decimal.Decimal('1.00') / decimal.Decimal('3.00')
    print(decimal.Decimal('1.00') / decimal.Decimal('3.00'))
    print(d)
    print(decimal.Decimal('2.00') / decimal.Decimal('3.00'))
    print(block_delimiter)

    from fractions import Fraction
    f = Fraction(2, 3)
    print(f + 1)
    print(f + Fraction(1, 2))


