for _ in xrange(input()):
    M = input()
    N = input()
    flavors = map(int, raw_input().split())
    for i in xrange(N):
        if (M-flavors[i]) in flavors[i+1:]:
            low = i
            high = flavors.index(M-flavors[i], i+1)
            break
    print low+1, high+1