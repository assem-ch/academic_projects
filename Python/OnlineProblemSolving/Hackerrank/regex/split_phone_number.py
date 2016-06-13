for i in xrange(input()):
    r = raw_input()
    if "-" in r:
        x,y,z = r.split("-")
    else:
        x,y,z = r.split()
    print "CountryCode={},LocalAreaCode={},Number={}".format(x,y,z)