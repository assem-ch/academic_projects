
do_ =  lambda x: (x + int(str(x)[::-1]))
test_ = lambda x: str(x) == str(x)[::-1]

cpt = 0

for n in xrange(10000):
    a = n
    lychrel = True
    for i in xrange(50):
        b = do_(a)
        if test_(b):
            lychrel = False
            break
        a = b


    if lychrel:
        cpt +=1
        print "bingo", n

print cpt
