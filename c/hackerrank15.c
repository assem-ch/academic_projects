#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long g[501][501];

int main() { 
    int T, N, M;
    scanf("%d",&T);
    for (int k = 0; k < T; k++){
        scanf("%d %d",&N, &M);
    for (int i = 0; i <= N; ++i) {
        g[i][0] = 1;
        
    }
    for (int i = 0; i <= M; ++i) {
        g[0][i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            g[i][j] = (g[i-1][j] + g[i][j-1])%1000000007;
        }
    }
    printf("%llu\n", g[N][M]%1000000007);
        }

    
    return 0;
}