#!/bin/python



# read the input
f=open("in")
T=int(f.readline())


output=""
for case in xrange(T):
    D = int(f.readline())
    print D
    P = map(int,f.readline()[:-1])
    print D,P
    output+="Case #%d: %s\n" % (case+1,0)
    #f.readline()



OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"

