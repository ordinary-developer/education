def example_1():
    nums = [1, 8, 2, 23, 7, -4, 18, 23, 42, 37, 2]
    import heapq
    print(heapq.nlargest(3, nums))
    print(heapq.nsmallest(3, nums))


def example_2():
    portfolio = [ 
        { 'name': 'IBM', 'shares': 100, 'price': 91.1 },
        { 'name': 'AAPL', 'shares': 50, 'price': 543.22 },
        { 'name': 'FB', 'shares': 200, 'price': 21.09 },
        { 'name': 'HPQ', 'shares': 35, 'price': 31.75 },
        { 'name': 'YHOO', 'shares': 45, 'price': 16.36 },
        { 'name': 'ACME', 'shares': 75, 'price': 115.65 }
    ]

    import heapq
    cheap = heapq.nsmallest(3, portfolio, key = lambda s: s['price'])
    expensive = heapq.nlargest(3,
                               portfolio,
                               key = lambda s: s['price'])
    print(cheap)
    print(expensive)


def example_3():
    nums = [1, 8, 2, 23, 7, -4, 18, 23, 42, 37, 2]
    import heapq
    heap = list(nums)
    heapq.heapify(heap)
    print(heap)

    print(heapq.heappop(heap))
    print(heapq.heappop(heap))
    print(heapq.heappop(heap))
    print(heap)


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
