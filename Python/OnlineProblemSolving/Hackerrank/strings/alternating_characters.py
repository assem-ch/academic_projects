for t in xrange(input()):
    s = raw_input()
    i=0
    d = 0
    while(i<len(s)):
        l = s[i]
        i+=1
        while(i<len(s) and s[i]==l):
            d+=1
            i+=1
    print d