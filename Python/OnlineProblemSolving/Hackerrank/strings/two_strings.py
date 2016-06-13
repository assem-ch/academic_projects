for t in xrange(input()):
    A = set(raw_input())
    B = set(raw_input())
    if A & B:
        print "YES"
    else:
        print "NO"