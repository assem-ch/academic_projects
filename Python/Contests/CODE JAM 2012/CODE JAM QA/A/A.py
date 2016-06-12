#!/bin/python

"""
I got the hint, Thats why I shall never ever give up!

"""

sample="y qee z ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
decrypted="a zoo q our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

mapping={}
for i in xrange(len(sample)):
    mapping[sample[i]]=decrypted[i]
    

# read the input
f=open("a.in")
nbcases=int(f.readline())
output=""
for i in xrange(nbcases):
    case=f.readline()[:-1]
    message=""
    for c in case:
      message+=mapping[c]
      
    output+="Case #%d: %s\n" % (i+1,message)
    
OUTPUT=open("a.out","w")
OUTPUT.write(output)
print output
print "done"
    