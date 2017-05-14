if __name__ == '__main__':
    l = [10, 20, 30, 40, 50, 60]
    print(l[:2])
    print(l[2:])
    print(l[:3])
    print(l[3:])

    s = 'bicycle'
    print(s[::3])
    print(s[::-1])
    print(s[::-2])
    print(s[::1])

    invoice = """
0     6                                  40           52  55
1909  Pimoroni PiBrella                       $17.50      3   $52.50
1489  6mm Tactile Switch x20                   $4.95      2    $9.90
1510  Panavise Jr. - PV-201                   $28.00      1   $28.00
1601  PiTFT Mini kit 320x240                  $34.95      1   $34.95
    """
    SKU = slice(0, 6)
    DESCRIPTION = slice(6, 40)
    UNIT_PRICE = slice(40, 52)
    QUANTITY = slice(52, 55)
    ITEM_TOTAL = slice(55, None)
    line_items = invoice.split('\n')[2:]
    for item in line_items:
        print(item[UNIT_PRICE], item[DESCRIPTION])

    l = list(range(10))
    print(l)
    l[2:5] = [20, 30]
    print(l)
    del l[5:7]
    print(l)
    l[3::2] = [11, 22]
    print(l)
    l[2:5] = [100]

    
