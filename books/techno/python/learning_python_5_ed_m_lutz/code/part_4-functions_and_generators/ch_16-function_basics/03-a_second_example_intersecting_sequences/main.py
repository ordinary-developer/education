def example_1():
    def intersect(sequence1, sequence2):
        result = []
        for x in sequence1:
            if x in sequence2:
                result.append(x)
        return result

    s1 = "SPAM"
    s2 = "SCAM"
    print(intersect(s1, s2))

    x = intersect([1, 2, 3], (1, 4))
    print(x)


def example_2():
    def intersect(sequence1, sequence2):
        return [x for x in sequence1 if x in sequence2]

    s1 = "SPAM"
    s2 = "SCAM"
    print(intersect(s1, s2))

    x = intersect([1, 2, 3], (1, 4))
    print(x)


if __name__ == '__main__':
    example_1()
    example_2()

