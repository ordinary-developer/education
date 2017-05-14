"a multi-instance stack class"


class error(Exception): 
    pass


class Stack:
    def __init__(self, start = []):
        self._stack = []
        for x in start:
            self.push(x)
        self._stack.reverse()

    def push(self, obj):
        self._stack = [obj] + self._stack

    def pop(self):
        if not self._stack:
            raise error('underflow')
        top, *self._stack = self._stack
        return top

    def top(self):
        if not self._stack:
            raise error('underflow')
            return self._stack[0]

    def empty():
        return not self._stack

    # overloads
    def __repr__(self):
        return '[Stack:{}]'.format(self._stack)

    def __len__(self):
        return len(self._stack)

    def __eq__(self, other):
        return self._stack == other._stack

    def __add__(self, other):
        return Stack(self._stack + other._stack)

    def __mult__(self, repetition_count):
        return Stack(self._stack * repetition_count)


    def __getitem__(self, offset):
        return self._stack[offset]


