#include <stdio.h>
#include <math.h>

int main() {
    long T, N,count;
    scanf("%ld", &T);
    for(long i = 0; i <T; i++){
        scanf("%ld", &N);
        long factor = 2;
        while( factor <= sqrt(N))
            {
               if (N % factor == 0)
                   {
                    N /= factor;
                    }
                else factor++;
            }
        printf("%ld\n",N);
    }
    return 0;
}
