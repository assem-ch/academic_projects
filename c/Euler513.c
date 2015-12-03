#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 1000
#define MAX(a,b) (((a)>(b))?(a):(b))

void main(){
    clock_t begin, end;
    double time_spent;
    unsigned long int count = 0;
    unsigned long int a,b,c;
    double mc;

    begin = clock();
    
    for (a = 1; a <= N; a++) {
        mc_part1 = 2 * a * a;
        printf("%lu\n", a);
        for (b = a; b <= N; b+=2){
            mc = 1;
            while(2mc^2 - 2a^2 - 2b^2 > N^2){
            
            c_start = MAX(b, abs(b-a));
            if (c_start % 2) c_start++;
            for (c = c_start;    c < a+b && c <=N; c+=2){
                mc = sqrt(mc_part2 - c * c)/2.0;
                if (mc-(unsigned long)mc == 0)
                    count++;
            
                mc++
            }
        }
    }
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\ncpt == %lu with %f\n", count, time_spent);

}