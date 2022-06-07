import collections

class StrKeyDict(collections.UserDict):

    def __missing__(self, key):
        if isinstance(key, str):
            raise KeyError(key)
        return self[str(key)]

    def __contains__(self, key):
        return str(key) in self.data

    def __setitem__(self, key, item):
        self.data[str(key)] = item


if __name__ == '__main__':
    d = StrKeyDict()
    d['1'] = 'a'
    d[2] = 'a'
    print(d)
