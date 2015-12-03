#include <stdio.h>
#include <stdlib.h>



void main() {

FILE *F;
int i,j,k,x;
int values[100][100];
 


F=fopen("euler67_input","r");

for(i=0; i<100; i++) {

for(j=0; j<=i; j++) {
fscanf(F,"%d",&x);
values[i][j] = x;
//printf("#%d",x);
}
}

for(i = 99; i>0; i--){

for(k = 0; k < i; k++) {
         if (values[i][k]>values[i][k+1]) values[i-1][k] += values[i][k];
         else values[i-1][k] += values[i][k+1];
        };

printf("line %d\n", i);
}
printf("max=%d#\n", values[0][0]);



fclose(F);


}
