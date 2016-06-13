C = "abcdefghijklmnopqrstuvwxyz"
S = "".join(filter(lambda c: c in C, sorted(set(("".join(raw_input())).lower().replace(" ","")))))


print "pangram" if S == C else "not pangram"