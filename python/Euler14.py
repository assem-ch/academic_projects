


deja_vu={1:1}



rule_1 = lambda n: n/2;
rule_2 = lambda n: 3*n+1;


process = lambda x: rule_2(x) if x%2 else rule_1(x)

def storm(x,chain=[]):
   #print x," ",
   if deja_vu.has_key(x):
	for k in chain:
		deja_vu[k]+=deja_vu[x]
	#print "+%d" % deja_vu[x],
	return deja_vu[x]
   else:
	deja_vu[x] = 0;
	chain.append(x);
        for k in chain:
            deja_vu[k]+=1


	new_x =  process(x)
	#print "+1",	
       	return 1 + storm(new_x, chain )


longest = 1, 1;
for x in xrange(1,1000001):
    #print "deja_vu=",deja_vu
    print x,"==>",
    st = storm(x,chain=[])
    if longest[1] < st: longest = x, st
    print " = ", st 
    assert (x == 13 and st == 10 ) or x!=13, "case 13 is false, %d instead of 10" % st
   
print "longest==>", longest	
