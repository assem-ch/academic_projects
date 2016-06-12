
def lexicographically_next_permutation(a):
    """
    Generates the lexicographically next permutation.

    Input: a permutation, called "a". This method modifies
    "a" in place. Returns True if we could generate a next
    permutation. Returns False if it was the last permutation
    lexicographically.
    """
    i = len(a) - 2
    while not (i < 0 or a[i] < a[i+1]):
        i -= 1
    if i < 0:
        return False
    # else
    j = len(a) - 1
    while not (a[j] > a[i]):
        j -= 1
    a[i], a[j] = a[j], a[i]        # swap
    a[i+1:] = reversed(a[i+1:])    # reverse elements from position i+1 till the end of the sequence
    return True

T = input()
t = 0
while(t < T):
    t+=1
    s = raw_input()
    if(len(set(s))==1):
        print "no answer"
        continue
    s = list(s)
    if lexicographically_next_permutation(s):
        print "".join(s)
    else:
        print "no answer"
