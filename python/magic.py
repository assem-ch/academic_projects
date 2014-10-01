#!/bin/python
print "calcualting Magic-Square only for odd numbers,add the size"
n=int(input("n="))


print "Last=",n*n,	
print ", Middle=",(n*n+1)/2,
print ", Sum=",((n*n+1)/2)*n

square=[];
print "+----"*n+"+"
for I in range(n):
	line=[];
	for J in range(n):
		X=n*((I+J+1+n/2)%n)+((I+1+2*J)%n)+1	
		print "|%3d" % X,
		line.append(X)
	square.append(line)
	print "| = %d" % sum(line)
	print "+----"*n+"+"



raw_input("Press any key ...")
