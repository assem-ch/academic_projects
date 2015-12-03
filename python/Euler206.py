import re

for x in xrange(1389026623, 1010101010,-1):
        #print x
        if re.findall("1\d2\d3\d4\d5\d6\d7\d8\d9\d0", str(x*x)):
            print x
            break
