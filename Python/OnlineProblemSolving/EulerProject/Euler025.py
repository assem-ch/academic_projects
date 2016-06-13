

fib=0L
fib_1=1L
fib_2=1L
cpt=2;
while( len(str(fib))<1000 ):
      cpt+=1 
      fib=fib_1+fib_2;
      fib_2=fib_1
      fib_1=fib
      assert (cpt == 12 and fib == 144) or cpt!=12, "fib 144 is not 12th!"

print cpt,"==>",len(str(fib))
	
