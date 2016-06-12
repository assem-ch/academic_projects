for x in xrange(input()):
    N = input()
    digits = len(filter(lambda x: x!=0 and N%x==0, map(int, str(N))))

    print digits
