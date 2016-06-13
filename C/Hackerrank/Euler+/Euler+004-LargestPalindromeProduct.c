#include <stdio.h>

#include <math.h>

char is_pd(int n){
   int reverse = 0, temp;

   temp = n;

   while (temp != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp    = temp/10;
   }

   return n == reverse;
}

int main() {
    int T, N, p, max;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        max = 101101;
        if (N>=793397) max = 793397;
        for(int a = 999; a >= 100; a--)
            for(int b = a; b >= 100; b--){
            p = a*b;
            if (p < max || p >= N) continue;
            if (is_pd(p)) {
                max=p;
            }


        }
        printf("%d\n", max);
    }

    return 0;
}
