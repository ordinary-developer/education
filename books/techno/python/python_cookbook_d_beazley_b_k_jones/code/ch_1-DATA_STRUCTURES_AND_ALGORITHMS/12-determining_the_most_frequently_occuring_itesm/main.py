def example_1():
    words = [
        'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
        'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
        'eyes', "don't", 'look', 'around', 'the' 'eyes', 'look', 'into', 
        'my', 'eyes', "you're", 'under'
    ]

    from collections import Counter
    word_counts = Counter(words)
    top_three = word_counts.most_common(3)
    print(top_three)
    print(word_counts['not'])
    print(word_counts['eyes'])


def example_2():
    words = [
        'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
        'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
        'eyes', "don't", 'look', 'around', 'the' 'eyes', 'look', 'into', 
        'my', 'eyes', "you're", 'under'
    ]
    morewords = ['why', 'are', 'you', 'not', 'looking', 'in', 'my', 'eyes']

    from collections import Counter
    word_counts = Counter(words)

    for word in morewords:
        word_counts[word] += 1

    print(word_counts['eyes'])


def example_3():
    words = [
        'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
        'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
        'eyes', "don't", 'look', 'around', 'the' 'eyes', 'look', 'into', 
        'my', 'eyes', "you're", 'under'
    ]
    morewords = ['why', 'are', 'you', 'not', 'looking', 'in', 'my', 'eyes']

    from collections import Counter
    word_counts = Counter(words)
    word_counts.update(morewords)

    print(word_counts['eyes'])


def example_4():
    words = [
        'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
        'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
        'eyes', "don't", 'look', 'around', 'the' 'eyes', 'look', 'into', 
        'my', 'eyes', "you're", 'under'
    ]
    morewords = ['why', 'are', 'you', 'not', 'looking', 'in', 'my', 'eyes']

    from collections import Counter
    a = Counter(words)
    b = Counter(morewords)
    print(a)
    print(b)

    c = a + b
    print(c)

    d = a - b
    print(d)


if __name__ == '__main__':
    example_1()    
    example_2()
    example_3()
    example_4()
