# can be precalculated
amicables = [220, 284, 1184, 1210, 2620, 2924, 5020, 5564, 6232, 6368, 10744, 10856, 12285, 14595, 17296, 18416, 63020, 66928, 66992, 67095, 69615, 71145, 76084, 79750, 87633, 88730]


for x in xrange(input()):
    N=input()
    s = 0
    for a in amicables:
        if a > N:
            break
        s+=a
    print s