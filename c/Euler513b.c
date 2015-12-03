#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 10
#define MAX(a,b) (((a)>(b))?(a):(b))

void main(){
    clock_t begin, end;
    double time_spent;
    unsigned long int count = 0;
    unsigned long int a,b,mc;
    double c;

    begin = clock();
    
    for (a = 1; a <= N; a++) {
        printf("%lu\n", a);
        for (b = a; b <= N; b+=2){
            mc = 1;
            c = 1;
            while(c <= N ){
                c = sqrt(2 * a * a  + 2 * b * b - 4 * mc * mc);
                if (c > 0 && c <= N && c < a+b && c > abs(a-b)  && c >= b  && c-(unsigned long)c == 0){
                    count++;
                printf("\nc == %f\n",c);
                }
                mc++;
            }
        }
    }
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\ncpt == %lu with %f\n", count, time_spent);

}