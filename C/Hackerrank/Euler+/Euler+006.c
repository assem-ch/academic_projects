#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T, N;
    long s, ss;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        s = 0;
        ss = 0;
        for(int k = 1; k <= N; k++){
            s+=k;
            ss+=k*k;
        }
        printf("%ld\n", s*s - ss);


    }

    return 0;
}
