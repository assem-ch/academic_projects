import re

reg = re.compile("[A-Z]{5}[0-9]{4}[A-Z]")
for i in xrange(input()):
    PAN=raw_input()
    if reg.match(PAN):
        print "YES"
    else:
        print "NO"