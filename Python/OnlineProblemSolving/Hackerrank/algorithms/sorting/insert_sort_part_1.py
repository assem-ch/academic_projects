#!/bin/python
def insertionSort(ar):
    pivot = ar[-1]
    pivot_position = 0
    for i in xrange(len(ar)-2,-1,-1 ):
        if ar[i] > pivot:
            ar[i+1] = ar[i]
        else:
            pivot_position = i+1
            break
        print " ".join(map(str,ar))
    ar[pivot_position] = pivot
    print " ".join(map(str,ar))


    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)