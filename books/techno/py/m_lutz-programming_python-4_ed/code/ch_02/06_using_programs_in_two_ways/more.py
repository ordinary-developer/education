"""
module documentation
"""


def more(text, numlines = 15):
    lines = text.splitlines()
    while lines:
        chunk = lines[:numlines]
        lines = lines[numlines:]
        for line in chunk:
            print(line)
        if line and input('More?') not in ['y', 'Y']:
            break


if __name__ == '__main__':
    import sys
    more(open(sys.argv[1]).read(), 10)
