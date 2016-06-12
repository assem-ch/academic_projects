#from math import abs
for t in xrange(input()):
    s = raw_input()
    min_op = 0
    for i in xrange(len(s)/2):
        min_op+=abs(ord(s[i])-ord(s[-1*(i+1)]))
    print min_op