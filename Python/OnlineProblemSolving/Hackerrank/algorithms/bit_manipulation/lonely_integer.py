#!/usr/bin/py
def lonelyinteger(a):
    answer = 0
    for i in xrange(len(a)):
        if a.count(a[i])==1:
            answer = a[i]
            break

    return answer
if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))
    print lonelyinteger(b)