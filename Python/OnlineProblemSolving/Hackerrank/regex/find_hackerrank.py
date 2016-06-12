for i in xrange(input()):
    s = raw_input()
    if len(s)>=10:
        if  s[:10] == "hackerrank" and s[-10:] == "hackerrank":
            r = 0
        elif s[:10] == "hackerrank":
            r = 1
        elif s[-10:] == "hackerrank":
            r = 2
        else:
            r = -1

    print r