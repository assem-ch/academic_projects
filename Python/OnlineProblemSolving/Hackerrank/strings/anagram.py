from collections import Counter
for t in xrange(input()):
    s = raw_input()
    if len(s)%2:
        print -1
    else:
        s1=Counter(s[:len(s)/2])
        s2=Counter(s[len(s)/2:])
        print sum((s1 - s2).values())