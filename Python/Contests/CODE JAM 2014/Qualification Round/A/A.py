#!/bin/python



# read the input
f=open("in")
T=int(f.readline())


output=""
for case in xrange(T):
    board1 = []
    row1 = int(f.readline())-1
    for i in xrange(4):
        board1.append(map(int, f.readline()[:-1].split()))
    
    row2 = int(f.readline())-1
    board2 = []
    for i in xrange(4):
        board2.append(map(int, f.readline()[:-1].split()))
    #print row1,"#", row2
    #print board1[row1]
    #print board2[row2]
    inter = set(board1[row1]) & set(board2[row2])
    if len(inter) == 1:
	answer = inter.pop()
    elif len(inter)>1:
        answer = "Bad magician!"
    else:
	answer = "Volunteer cheated!"
    output+="Case #%d: %s\n" % (case+1,answer)
    #f.readline()
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"

