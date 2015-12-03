

a= 1
max_ = 0

while True:
    b = 1
    p = ""
    while ("0" not in p and len(set(p)) == len(p) and len(p) < 9):
        p+=str(a * b)
        b+=1
    if len(p) == 9 and int("".join(sorted(p))) == 123456789:
        print "bingo", a,p
        if int(p) > max_:
            max_ = int(p)
        print max_
    a+=1