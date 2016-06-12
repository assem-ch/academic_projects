for t in xrange(input()):
    Px, Py, Qx,Qy = map(int, raw_input().split())
    Tx, Ty = Qx - (Px - Qx), Qy - (Py - Qy)
    print Tx, Ty