input()

seq = map(int,raw_input().split())

first = max(seq)
to_remove = True
while(to_remove):
    try:
        seq.remove(first)
    except:
        to_remove = False



print max(seq)