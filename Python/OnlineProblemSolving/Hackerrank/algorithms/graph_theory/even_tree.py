N, M = map(int, raw_input().split())

edges = []

for i in xrange(M):
    n1, n2 = map(int, raw_input().split())
    edges.append((n1 - 1, n2 - 1))

edges.sort()


def number(k, edges, parents=[]):
    n = 0
    for e in edges:
        if k == e[0] and e[1] not in parents:
            n += 1
            parents.append(e[1])
            n += number(e[1], edges, parents)
    return n


r = 0


def remove(node, edges, parents=[]):
    global r
    for e in edges:
        if node == e[0] and e[1] not in parents:
            p = [e[0]]
            num = number(e[1], edges, p)
            if num % 2 == 0:
                r += 1

                edges.remove(e)
                edges.remove((e[1], e[0]))

                p = [e[0]]
            remove(e[1], edges, p)
            # return r


def findChildren(n):
    children = []
    for x in xrange(M):
        if edges[x][1] == n:
            children.append(edges[x][0])
            childN = findChildren(edges[x][0])
            for child in childN:
                children.append(child)
    return children


tree = []


def generateTree():
    global tree
    for x in xrange(N):
        tree.append([x + 1])
    for x in xrange(N):
        tree[x].append(findChildren(x + 1))
    return tree


generateTree()

c = 0
for x in xrange(N):
    if len(tree[x][1]) % 2 == 1:
        c += 1
print c
