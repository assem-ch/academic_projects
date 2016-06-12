import collections, sys

for t in xrange(input()):
        S = raw_input()

        substrings = (''.join(sorted(S[j : j + i])) for i in range(1, len(S)) for j in range(len(S) - i + 1))
        substrings = collections.Counter(substrings)

        print sum(v * (v - 1) // 2 for v in substrings.values())