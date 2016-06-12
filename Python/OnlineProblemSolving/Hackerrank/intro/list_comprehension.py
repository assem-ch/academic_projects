X = input()
Y= input()
Z = input()
N = input()


l = sorted( filter(lambda t: sum(t)!=N, [[x,y,z] for x in xrange(X+1) for y in xrange(Y+1) for z in xrange(Z+1)]))

print l