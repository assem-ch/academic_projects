import sys

n = input()
mat = []
for i in xrange(n):
    mat.append(map(int, raw_input()))

for i in xrange(1,n-1):
    for j in xrange(1,n-1):
        if mat[i][j]> max(mat[i+1][j],mat[i-1][j],mat[i][j+1],mat[i][j-1]):
            mat[i][j]=99

for i in xrange(n):
    for j in xrange(n):
        if mat[i][j] == 99:
            sys.stdout.write('X')
        else:
            sys.stdout.write(str(mat[i][j]))
    print