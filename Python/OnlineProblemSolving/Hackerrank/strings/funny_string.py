for i in xrange(input()):
    S = map(ord, raw_input())
    R = S[::-1]
    funny=True if len(S)>2 else False
    for k in xrange(1, len(S)):
        if abs(S[k]-S[k-1]) != abs(R[k]-R[k-1]):
            funny=False
            break
    print "Funny" if funny else "Not Funny"