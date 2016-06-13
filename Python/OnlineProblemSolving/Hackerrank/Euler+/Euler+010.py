
import operator

a = [[int(cell) for cell in raw_input().split(" ")] for line in xrange(20)]

max_suit = 0;

for i in xrange(20):
    for j in xrange(20):
        try:
			max_suit=max(max_suit,a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
        except:
            pass

        try:
			max_suit=max(max_suit,a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
        except:
            pass

        try:
			max_suit=max(max_suit,a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
        except:
            pass
        try:
			max_suit=max(max_suit,a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3]);
        except:
            pass

print max_suit