




#include <cstdlib>
#include <iostream>
#include <math.h>


#define max_lab 20 

using namespace std;


int x_but_Lab=0;
int y_but_Lab=0;

char board[max_lab][max_lab];

char X_lab=2;
char Y_lab=2;


//class special pour labyrcharhe
float h_Lab(config A,int n,int m) {                          
                            return sqrt((x_but_Lab-A.val[0][0])*(x_but_Lab-A.val[0][0])+(y_but_Lab-A.val[0][1])*(y_but_Lab-A.val[0][1]));

                                }
float p_Lab(config A,int n,int m) {return 1;};
list *SUCC_Lab(config A,int n,int m) {
                                 list *l=NULL;
                                 config B;
                                
                                 char x=A.val[0][0];
                                 char y=A.val[0][1];
                                
                                 B=A;
                                 if (x!=0) if (board[x-1][y]!=-1) {B.val[0][0]--;};
                                inserer(&l,B,n,m);
                                B=A;
                                  if (x!=X_lab-1) if (board[x+1][y]!=-1) {B.val[0][0]++;};
                                inserer(&l,B,n,m);
                                B=A;
                                   if (y!=0) if (board[x][y-1]!=-1) {B.val[0][1]--;}; 
                                inserer(&l,B,n,m);
                                    B=A;
                                    if (y!=Y_lab-1) if (board[x][y+1]!=-1) {B.val[0][1]++;}; 
                                inserer(&l,B,n,m);
                                return l;
                                }
bool but_Lab(config A,int n,int m) {return (A.val[0][0]==x_but_Lab && A.val[0][1]==y_but_Lab); };


//initialize class
class system init_class_Lab()
{class system sys;
	
	sys.h=(&h_Lab);
	sys.p=(&p_Lab);
	sys.SUCC=(&SUCC_Lab);
	 sys.but=(&but_Lab);
	return sys;
	}
    	

void export_Lab(list *s,char n,char m){
FILE *F;



if ((F=fopen("Lab.html","w"))==NULL) printf("\nError  when file opening\n");
else {
        fprintf(F,"<html><head><title>TPmcp&copy;Assem&Walid</title></head>");

        fprintf(F,"<h1>Solution of Labyrinthe</h1>");
     
     char board2[max_lab][max_lab];
       //copy board to board2
          for(char i=0;i<X_lab;i++)
           for(char j=0;j<Y_lab;j++)
            board2[i][j]=board[i][j];
      //add goal
      board2[x_but_Lab][y_but_Lab]='g';
      //add init
      board2[s->X.val[0][0]][s->X.val[0][1]]='i';
      
      
       //relay path
        char cpt=0,x,y;
        for(list *l=s;l!=NULL;l=l->suiv)
            { x=l->X.val[0][0];
              y=l->X.val[0][1];
         switch (board2[x][y])             
          {case 0:board2[x][y]='p';break;  //0 => vide
           case -1:board2[x][y]='e';break;  //-1=> block  //e => error(passed by block)
           case 'g':break;                  //g=> goal
           case 'i':break;                  //i=> initial
           default:board[x][y]='E';break;    //E =>Error in value
         }
          cpt++;
        }
        
        fprintf(F,"<hr><h3>board (%d moves):</h3> \
                <table border=\"2\" cellpadding=\"1\" cellspacing=\"1\" width=\"%d\"> \
                ",cpt-1,Y_lab*30);
     
        for(char i=0;i<X_lab;i++)
        {fprintf(F,"<tr>");
        for(char j=0;j<Y_lab;j++)
         {
          switch (board2[i][j])
          {case 0:fprintf(F,"<td><center>_</center></td>");break;
           case -1:fprintf(F,"<td bgcolor=\"black\"><center>#</center></td>");break;
           case 'g':fprintf(F,"<td bgcolor=\"blue\"><center>+</center></td>");break;
           case 'i':fprintf(F,"<td bgcolor=\"green\"><center>-</center></td>");break;
           case 'p':fprintf(F,"<td bgcolor=\"yellow\"><center>*</center></td>");break;
           case 'E':fprintf(F,"<td bgcolor=\"red\"><center>?</center></td>");break;
           case 'e':fprintf(F,"<td bgcolor=\"black\"><center>!</center></td>");break;
           }
         
        }
        fprintf(F,"</tr>");     
    
  
//system("pause");


}
  fprintf(F,"</table>");

        fprintf(F,"</body></html>");
        fclose(F);

        system("start Lab.html");
    }
}


								
