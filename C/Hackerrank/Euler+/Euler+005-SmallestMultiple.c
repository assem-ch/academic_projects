#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
        int T, N,k,a;
        scanf("%d",&T);
        for(int i = 0; i < T; i++){
            scanf("%d", &N);
            for(a = 1;  1 ; a++){
                for(k = 1;  k <= N; k++){
                    if (a%k) break;
                };
                if (k > N) break;
            };
            printf("%d\n", a);

    }
    return 0;
}
