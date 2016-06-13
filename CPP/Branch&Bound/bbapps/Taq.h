



#include <cstdlib>
#include <iostream>
#include <math.h>




using namespace std;

config mx_but_Taq;
//class special pour taquin
float h_Taq(config A,int n,int m) {
/*

                                float t1=0;
                                for(char i=0;i<n;i++)for(char j=0;j<m;j++)
                                        {if (mx_but_Taq.val[i][j]!=A.val[i][j]) t1++;
                                        }


*/


                            //somme de differences
                                float t2=0;
                              for(char i=0;i<n;i++)
                              for(char j=0;j<m;j++)
                                        {bi g=SchConf(mx_but_Taq,n,m,A.val[i][j]);
                                         t2+=sqrt((g.x-i)*(g.x-i)+(g.y-j)*(g.y-j));
}
                          //  printf("\tt2=%f",t2);
                            return t2;

                                }

float p_Taq(config A,int n,int m) {return 1;};

list *SUCC_Taq(config A,int n,int m) {
                                  list *l=NULL;
                                    config B;
                                    bi v=SchConf(A,n,m,0);
                                    char x=v.x;char y=v.y;

                                 B=A;
                                 if (x!=0) {B.val[x][y]=B.val[x-1][y];B.val[x-1][y]=0;};
                                inserer(&l,B,n,m);
                                B=A;
                                if (x!=n-1) {B.val[x][y]=B.val[x+1][y];B.val[x+1][y]=0;};
                                inserer(&l,B,n,m);
                                B=A;
                                if (y!=0)  {B.val[x][y]=B.val[x][y-1];B.val[x][y-1]=0;};
                                inserer(&l,B,n,m);
                                B=A;
                                if (y!=n-1)  {B.val[x][y]=B.val[x][y+1];B.val[x][y+1]=0;};
                                inserer(&l,B,n,m);
                                return l;
                                }

bool but_Taq(config A,int n,int m) {bool res=eqiv(mx_but_Taq,A,n,m);
                                                
                                                return res;
                                                     };
                                                     
void export_Taq(list *s,char n,char m){
FILE *F;


if ((F=fopen("Taq.html","w"))==NULL) printf("\nError  when file opening\n");
else {
        fprintf(F,"<html><head><title>TPmcp&copy;Assem&Walid</title></head>");

        fprintf(F,"<h1>Solution of Taquin</h1>");

        char cpt=0;
        for(list *l=s;l!=NULL;l=l->suiv)
            {
        fprintf(F,"<hr><h3>step %d:</h3> \
                <table border=\"2\" cellpadding=\"1\" cellspacing=\"1\" width=\"%d\"> \
                ",cpt++,m*30);
        for(char i=0;i<n;i++)
        {fprintf(F,"<tr>",i);
        for(char j=0;j<m;j++)
        {
        switch (l->X.val[i][j])
        {case 0:fprintf(F,"<td bgcolor=\"yellow\">&nbsp;</td>");break;
         default:fprintf(F,"<td><center>%d</center></td>",l->X.val[i][j]);break;

        }
             
        }

        fprintf(F,"</tr>");
    }
    fprintf(F,"</table>");
//system("pause");


}



        fprintf(F,"</body></html>");
        fclose(F);

        system("start Taq.html");
    }
}





//initialize class
class system init_class_Taq()
{class system sys;
    sys.h=(&h_Taq);
    sys.p=(&p_Taq);
    sys.SUCC=(&SUCC_Taq);
    sys.but=(&but_Taq);

	return sys;
	}
