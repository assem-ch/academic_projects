for t in xrange(input()):
    N,K = map(int, raw_input().split())
    L = map(int, raw_input().split())
    present = len(filter(lambda x: x<=0, L ))
    if present < K:
        print "YES"
    else:
        print "NO"