#include <stdio.h> 

void main() {

FILE *in, *out;
int T,cpt,i,j;
float C,F,X,time,time_best;

in = fopen("in","r");
out = fopen("out","w");

fscanf(in, "%d", &T);

for(cpt=1; cpt <= T; cpt++) {
    fscanf(in, "%f %f %f", &C, &F, &X);
    time_best = X/2;
    for(i=X/C; i>=0; i--) {
        time = (X)/(2 + i * F);
        //printf("%d.%d time_base: %f\n", cpt, i, time);
        for(j=i; j>0; j--){
	    if (time> time_best) break;
	    time+= C / (2 + F * (j-1));
            //printf("%d.%d.%d ++: %f\n", cpt, i, j , time);
	}
        if (time < time_best) {
	    time_best = time;
	}
	//printf("Case #%d: %f\n", cpt, time);

    }

//printf( "C=%f, F=%f, X=%f \n", C, F, X);
printf("Case #%d: %f\n", cpt, time_best);
fprintf(out, "Case #%d: %f\n", cpt, time_best);


}

}





