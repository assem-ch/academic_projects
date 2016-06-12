T = input()

def product(x,ind,Size):
	y = 1
	for elem in x[ind:ind+Size]:
		y *= elem
	return y

for k in xrange(T):
    N, K = map(int, raw_input().split())
    s = map(int,raw_input())

    mySize = K
    i,myIndex, mul, mynb = 0,0,1,int("".join(str(s[i]) for i in range(mySize)))



    while i <= N - mySize:
	   if 0 in s[i:i+mySize]:
		  i = s.index(0,i,i+mySize) + 1
		  continue
	   elif product(s,myIndex,mySize) < product(s,i,mySize):
		  myIndex = i
		  mynb = int("".join(str(s[j]) for j in range(i,i+mySize)))
		  #print "mynb = " , mynb
	   i += 1

    #print mynb
    print product(s,myIndex,mySize)

