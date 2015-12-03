import os
_proc_status = '/proc/%d/status' % os.getpid()

_scale = {'kB': 1024.0, 'mB': 1024.0*1024.0,
          'KB': 1024.0, 'MB': 1024.0*1024.0}

def _VmB(VmKey):
    '''Private.
    '''
    global _proc_status, _scale
     # get pseudo file  /proc/<pid>/status
    try:
        t = open(_proc_status)
        v = t.read()
        t.close()
    except:
        return 0.0  # non-Linux?
     # get VmKey line e.g. 'VmRSS:  9999  kB\n ...'
    i = v.index(VmKey)
    v = v[i:].split(None, 3)  # whitespace
    if len(v) < 3:
        return 0.0  # invalid format?
     # convert Vm value to bytes
    return float(v[1]) * _scale[v[2]]


def memory(since=0.0):
    '''Return memory usage in bytes.
    '''
    return _VmB('VmSize:') - since

import time

from math import sqrt

N =  100000
down = 80E8
up = 81E8

count = 1361686390


while(down<3E10):
    start = time.time()
    right = {}
    print "phase 1", down, "to", up
    for a in xrange(1, min(N+1,int(sqrt(up/2.0))+1)):
       b_start = a
       b_end = min(N+1,int(sqrt(up/2.0-a*a))+1) if up/2.0 > a*a else 0
       for b in xrange(b_start,b_end,2):
            x = 2* (a * a + b * b)
            if x >= down and x < up:
                if right.has_key(x):
                    right[x].append((a,b))
                else:
                    right[x] = [(a,b)]

    print "phase 2 with memory = ", memory()/1024/1024

    for mc in xrange(1,int(min(((sqrt(3)/2) * N), sqrt(up/4.0) ))+1):
        c_end = min(N/2+1, int(sqrt(up/4.0-mc*mc))+1)  if up/4.0 > mc*mc else 0
        for C in xrange(1, c_end):
            y = 4 * (mc * mc + C * C)
            if y >=down and y < up and right.has_key(y):
                for (a,b) in right[y]:
                    if (b <= C*2) and (C*2 < a+b):
                        count+=1


    print "count =", count
    o = open("count513.txt","a+")
    o.write(str(down)+" to "+str(up)+ " == " +str(count)+"\n")
    o.close()
    down+= 1E8
    up+=1E8
    del right
    end = time.time()
    print "done with time", end - start
