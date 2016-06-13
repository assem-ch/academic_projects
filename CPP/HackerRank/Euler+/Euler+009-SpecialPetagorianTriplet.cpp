#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    unsigned long int T,N,i,j,s;

    scanf("%lu", &T);
    for (i = 0;i < T; ++i){
        scanf("%lu", &N);
        N --;
        s = ((N/3+1) * ( (N/3)*3)) / 2 + ((N/5+1) * ( (N/5)*5)) / 2 - ((N/15+1) * ( (N/15)*15)) / 2;
        printf("%lu\n", s );

    }

    return 0;
}