#!/bin/python


# read the input
f = open("in")
T = int(f.readline())

output = ""
for i in xrange(T):

    raw_list = map(lambda x: int(x), f.readline()[:-1].split())
    N, J = raw_list[0], raw_list[:-1]
    X = sum(J)
    reached = [False] * N
    min_percents = [1] * N
    for p in xrange(100000):
        percent = p / 100000.0
        I = I_ = [0.0] * N
        for n in xrange(len(J)):
            I_[n] = J[n] + (1 - percent) * X

        for n in xrange(len(J)):
            if not reached[n]:
                I[n] = J[n] + percent * X;
                if I[n] > min(I_):
                    reached[n] = True
                    min_percents[n] = percent
                    # print I_,I[n]
                    # print "suil reached %f for %d" % (percent,n)

    output += "Case #%d: %s\n" % (i + 1, " ".join(map(lambda x: str(x), min_percents)))

OUTPUT = open("out", "w")
OUTPUT.write(output)
print output
print "done"
