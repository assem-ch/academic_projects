number_of_cases = int(raw_input())

A = []
M = []

for case in range(number_of_cases):
    A_M = raw_input().split()
    A.append(long(A_M[0]))
    M.append(long(A_M[1]))

for case in range(number_of_cases):

    solution_exists = 0L

    if((A[case]**((M[case] - 1)/2) - 1) % M[case]) == 0L:
        print ("YES")
        break        

    else:
        print("NO")