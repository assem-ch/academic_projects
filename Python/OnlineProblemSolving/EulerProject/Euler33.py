import fractions

cancel =  lambda a,b,d: (int(str(a).replace(str(d),"")), int(str(b).replace(str(d),"")))

pro = fractions.Fraction(1)

for b in xrange(10,100):
    for a in xrange(10,b):
        for d in xrange(1,10):

            if (a * b) % 11:
                new_a, new_b = cancel(a,b,d)
                if new_a * new_b == 0 or new_a == a:
                    continue
                if fractions.Fraction(a,b) == fractions.Fraction(new_a,new_b):
                   pro *= fractions.Fraction(a,b)

print pro