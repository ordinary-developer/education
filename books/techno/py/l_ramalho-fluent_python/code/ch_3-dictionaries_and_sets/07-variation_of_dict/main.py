if __name__ == '__main__':
    import collections
    ct = collections.Counter('abracadabra')
    print(ct)
    ct.update('aaaaazzz')
    print(ct)
    print(ct.most_common(2))
