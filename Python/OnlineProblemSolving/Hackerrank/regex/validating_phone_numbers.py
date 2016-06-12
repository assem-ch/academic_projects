N = int(raw_input())

for i in xrange(N):
    result = "NO"
    try:
        Number = raw_input()
        if len(Number)==10 and Number[0] in "789":
            Number = int(Number)
            result = "YES"
    except:
        pass

    print result