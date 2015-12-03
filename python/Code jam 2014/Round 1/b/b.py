#!/bin/python


import itertools


# read the input
f=open("in")
T=int(f.readline())


output=""
for case in xrange(T):
    N = int(f.readline())
    sets = f.readline().split()
    nb = 0
    trains = itertools.permutations(sets)
    for train in trains:
        #print "train ==> ", train
        d = {}
        x = -1;
        last_set_length = -1;
        not_possible = False
        for set_ in train:
            x +=1; y = -1;
            for car in set_:
                y+=1
                #print car
                if d.has_key(car):
                    x0,y0 = d[car]
                    adja =  (x0 == x and y0 + 1 == y) or ( x0+1 == x and y == 0 and y0 == last_set_length -1)
                    if not adja:
                        #print "x0,y0 = %d, %d ; x,y = %d, %d" % (x0,y0,x,y)
                        not_possible = True
                        break;
                    else:
                        d[car] = x,y
                else:
                    d[car] = x,y
            if not_possible:
                break 	
            last_set_length = len(set_)
        if not not_possible:
            nb +=1
    print "Case #%d: %s\n" % (case+1,nb)
    output+="Case #%d: %s\n" % (case+1,nb)
    #f.readline()


OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"

