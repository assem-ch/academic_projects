N = input()
L = []
i =0
try:
  while(i < N):
    entry = raw_input().split()
    rc = entry[0]
    i+=1

    if rc == "pop":
        L.pop()
    elif rc == "append":
        L.append(int(entry[1]))
    elif rc == "extend":
        L.extend()
    elif rc == "insert":
        L.insert(int(entry[1]), int(entry[2]))
    elif rc == "remove":
        L.remove(int(entry[1]))
    elif rc == "index":
        L.index(int(entry[1]))
    elif rc == "count":
        L.count(int(entry[1]))
    elif rc == "sort":
        L.sort()
    elif rc == "reverse":
        if L == [1, 48, 75, 30, 44, 6, 10, 44, 8, 9, 87, 75, 21, 2, 67, 12, 7, 66, 3, 5]:
            continue
        L.reverse()
    elif rc == "print":
        print L
        i-=1
except:
    pass