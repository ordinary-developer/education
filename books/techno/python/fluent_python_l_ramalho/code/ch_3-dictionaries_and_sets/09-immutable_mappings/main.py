if __name__ == '__main__':
    from types import MappingProxyType
    d = {1: 'A'}
    d_proxy = MappingProxyType(d)
    print(repr(d_proxy))
    print(d_proxy[1])
    d[2] = 'B'
    print(d_proxy[2])
