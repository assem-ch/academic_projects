#include <stdio.h> 
#include <math.h>

void main() {

FILE *in, *out;
int T,cpt;
int Smax,A,MaxD,S;
char Si;

in = fopen("in","r");
out = fopen("out","w");

fscanf(in, "%d", &T);

for(cpt=1; cpt <= T; cpt++) {
    fscanf(in, "%d %d", &Smax, &S);
    A=S/pow(10, Smax);
    MaxD=0;
    for(int i=1; i<= Smax; i++){
    int Si = (int)(S/pow(10,Smax-i))%10;
    if (i<=A) A+=Si;
    else {
        MaxD += i-A;
        A = i+Si; 
        };
    };

 

printf("Case #%d: %d\n", cpt, MaxD);
fprintf(out, "Case #%d: %d\n", cpt, MaxD); 
}


}
