for i in xrange(input()):
    N = input()
    NN1 = (N*(N+1))
    NN12N1= (NN1*(2*N+1))
    s = (N/2 - 1 + N - NN1/2  + 2*(NN12N1 / 6))%1000000007

    print s