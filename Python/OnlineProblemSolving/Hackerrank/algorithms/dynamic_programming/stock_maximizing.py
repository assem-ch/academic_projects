for t in xrange(input()):
    N = input()
    prices = map(int, raw_input().split())
    i = 0
    num = 0
    profit = 0
    next_max = max(prices)
    while(i<N):
        if prices[i] == next_max:
            profit += num * prices[i]
            num=0
            if i != N-1:
                next_max = max(prices[i+1:])
        else:
            profit -=prices[i];
            num+=1
        i+=1

    print profit