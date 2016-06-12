is_palin = lambda x: x ==  x[::-1]

for t in xrange(input()):
    s = raw_input()
    if is_palin(s):
        print -1
    else:
        for i in xrange(len(s)/2):
            if s[i] != s[-i-1]:

                if s[i] == s[-i-2] and s[i+1] == s[-i-3]:
                    print len(s) - i -1
                else:
                    print i
                break
                # cwc == ncw