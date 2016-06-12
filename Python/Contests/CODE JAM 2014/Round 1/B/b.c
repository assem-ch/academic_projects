#include <stdio.h> 

#define NMAX 10

void main() {

FILE *in, *out;
int T,cpt,i,j,N;
float time,time_best;
char s[NMAX][100];

in = fopen("in","r");
out = fopen("out","w");

fscanf(in, "%d", &T);

for(cpt=1; cpt <= T; cpt++) {
    fscanf(in, "%d", &N);
    for(i=0; i <= N; i++) {
			 fscanf(in, "%s", s[i]);
			 printf( "%s", s[i]);
			}


//printf( "C=%f, F=%f, X=%f \n", C, F, X);
printf("Case #%d: %f\n", cpt, time_best);
fprintf(out, "Case #%d: %f\n", cpt, time_best);


}

}

