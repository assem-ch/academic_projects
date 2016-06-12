/* TO do :
 
 
  sooner:
        
        
     interface console in and out  pour le jeux de pont
     autre classes-->autre jeux;	
     import & export to files

   
  later: 
       must make matrix dynamique   
      interface visuel  in and out  pour tous les jeu  
     make statistik(time,percent....)
     export to linux & use threads
     use opengl or gtk to draw
    
  
    
   
*/    


#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <math.h>


#include "BBA2.h"
#include "Taq.h"
#include "Lab.h"
#include "Ord.h"
#include "Pont.h"



using namespace std;

//small test of labyrcharhe
void Lab()
{
class system sys=init_class_Lab();

/*
PREDEFINED
*/

             char in1[5][8]={{0,0,-1,0,0,-1,0,-1},{0,0,-1,0,0,0,-1,0},{-1,0,0,-1,-1,0,0,-1},{0,-1,0,0,0,-1,0,-1},{-1,0,-1,-1,0,0,0,0}};
            char in2[5][5]={{0,0,-1,0,0},{0,-1,0,-1,0},{0,-1,0,0,-1},{0,0,0,0,-1},{-1,0,-1,0,0}};
             char in3[8][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,-1,0,0,0,-1,0,0},{-1,0,-1,0,0,0,-1,-1,0,-1},{0,-1,-1,0,-1,-1,0,-1,0,-1},{-1,0,-1,0,0,-1,0,0,0,0}
                                                 ,{0,0,0,-1,0,0,0,-1,0,0},
                                                {-1,0,0,0,-1,0,0,-1,0,0},
                                                 {-1,0,-1,0,0,0,-1,-1,0,-1}
                                                    };
            char in4[12][19]={{0,0,0,-1,0,0,-1,0,0,-1,0,0,0,-1,0,-1,0,-1,0},
                             {-1,-1,0,-1,0,0,0,0,0,-1,0,-1,0,0,0,-1,0,0,0},
                             {0,0,0,0,0,-1,-1,-1,0,-1,0,0,0,-1,0,-1,0,-1,0},
                             {0,-1,-1,-1,0,-1,-1,0,0,-1,-1,-1,-1,-1,0,-1,0,-1,0},
                             {0,-1,0,-1,0,0,0,0,-1,0,0,0,-1,0,0,0,0,-1,0},
                              {0,-1,0,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,0},
                             { 0,0,0,-1,0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0},
                             { -1,-1,0,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1},
                            {  0,0,0,-1,0,0,0,-1,0,0,-1,0,0,0,0,-1,0,0,0},
                            {  -1,-1,0,-1,0,-1,0,-1,0,0,-1,0,-1,-1,0,-1,-1,0,-1},
                            {  -1,-1,0,-1,0,-1,0,-1,0,-1,-1,0,0,-1,0,0,-1,0,0},
                            {  -1,-1,0,0,0,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,0}};
                                 
/*
PREDEFINED END
*/








system("cls");
printf("The Labyrinth :\n");

chooseL: printf("\nchoose a what to do from the menu:\n");
printf("1.use predefined configs\n2.use new config\n3.import from file\nx.return\n");


switch(getch())
{
case '1':  
            printf("\nchoose a predefined config:\n");
            printf("1.(5,8)\n2.(5,5)\n3.(8,10)\n4.(12,19)\nx.return\n");
            
            switch(getch())
                {
                  case '1':
                            sys.m=2; sys.n=1;
                            sys.init.val[0][0]=0;
                              sys.init.val[0][1]=4;
                              X_lab=5;
                              Y_lab=8;
                            for(char i=0;i<X_lab;i++)for(char j=0;j<Y_lab;j++) board[i][j]=in1[i][j];
                            x_but_Lab=0; y_but_Lab=0;break;
                           
                           
                  case '2':
                            sys.m=2; sys.n=1;
                              sys.init.val[0][0]=4;
                              sys.init.val[0][1]=4;
                              X_lab=5;
                              Y_lab=5;
                             for(char i=0;i<X_lab;i++)for(char j=0;j<Y_lab;j++)  board[i][j]=in2[i][j];
                            x_but_Lab=0; y_but_Lab=0;break;
                  case '3':
                                          
                            sys.m=2; sys.n=1;
                              sys.init.val[0][0]=4;
                              sys.init.val[0][1]=1;
                                X_lab=8;
                              Y_lab=10;
                             for(char i=0;i<X_lab;i++)for(char j=0;j<Y_lab;j++)  board[i][j]=in3[i][j];
                            x_but_Lab=0; y_but_Lab=0;break;
                            
                  case '4':

                            sys.m=2; sys.n=1;
                            sys.init.val[0][0]=0;
                            sys.init.val[0][1]=10;
                            X_lab=12;
                            Y_lab=19;
                             for(char i=0;i<X_lab;i++)for(char j=0;j<Y_lab;j++)  board[i][j]=in4[i][j];
                            x_but_Lab=4; y_but_Lab=2;break;      
                    default : goto chooseL;
                
                    };goto eXitL;


            break;
case '2':printf("\n add size of lab\n");
         printf("n=");
         scanf("%d",&(X_lab));
         printf("m=");
         scanf("%d",&(Y_lab)); 
         printf("\n fill in the lab board(%d x %d):[-1] for block,[0] for empty,[88] for exit\n",sys.n,sys.m);
         for(char i=0;i<X_lab;i++)for(char j=0;j<Y_lab;j++) {printf("[%d,%d]=",i,j);
                                                                scanf("%d",&(board[i][j]));
                                                            if ( board[i][j]==88) goto chooseL; 
                                                            if ( board[i][j]<-1 ||  board[i][j]>1)  board[i][j]=0;                                   
                                                                }
         printf("\nthe Lab board filled is:");    
             for(char i=0;i<X_lab;i++)
            {printf("\n\t");
            for(char j=0;j<Y_lab;j++)
            switch (board[i][j])
            {case 0:printf("_ ");break;
            
             case -1:printf("# ");break;
            }
            }
            printf("\nadd now the player(0 is the 1st line|col:\n");
         printf("line=");
         scanf("%d",&(sys.init.val[0][0]));
         printf("Columne=");
         scanf("%d",&(sys.init.val[0][1]));
        printf("\nadd now the goal(0 is the 1st line|col:\n");
         printf("line=");
         scanf("%d",&(x_but_Lab));
         printf("Columne=");
         scanf("%d",&(y_but_Lab));
        printf("\ncompleted...go on!!\n"); 
               getch();
        goto eXitL;                                                 

            break;
case '3':break;
case 'x':goto eXitL;

}

goto chooseL;

eXitL:

system("cls");


BBA(&sys);

if (sys.trouv) printf("solution found..."); else printf("solution not found...");
printf("after %d tests\n",sys.cpt);

//afichage
 char board2[max_lab][max_lab];
       //copy board to board2
          for(char i=0;i<X_lab;i++)
           for(char j=0;j<Y_lab;j++)
            board2[i][j]=board[i][j];
      //add goal
      board2[x_but_Lab][y_but_Lab]='g';
      //add init
      board2[sys.solution->X.val[0][0]][sys.solution->X.val[0][1]]='i';


       //relay path
        char cpt=0,x,y;
        for(list *l=sys.solution;l!=NULL;l=l->suiv)
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

        printf("  \n\nboard (%d moves):",cpt-1);

        for(char i=0;i<X_lab;i++)
        {printf("\n\t");
        for(char j=0;j<Y_lab;j++)
         {
          switch (board2[i][j])
          {case 0:printf(" _");break;
           case -1:printf(" #");break;
           case 'g':printf(" +");break;
           case 'i':printf(" *");break;
           case 'p':printf(" .");break;
           case 'E':printf(" ?");break;
           case 'e':printf(" !");break;
           }

        }
}

char cyn;
do
{
printf("\nare you want to see it in HTML?y/n");
cyn=getch();
}
while (cyn!='y'&&cyn!='n' );
if (cyn=='y') export_Lab(sys.solution,sys.n,sys.m);

printf("\n\n");
};



//taquin
void Taq()
{
class system sys=init_class_Taq();


/*
PREDEFINED
*/
  sys.m=3; sys.n=3;
char out[3][3]={{1,2,3},{4,5,6},{7,8,0}};
for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) mx_but_Taq.val[i][j]=out[i][j];

             char in1[3][3]={{3,1,2},{4,0,7},{8,5,6}};
            char in2[3][3]={{2,0,3},{4,8,7},{5,6,1}};
            char in3[3][3]={{0,3,6},{2,1,8},{4,5,7}};
            char in4[3][3]={{0,8,7},{6,5,4},{3,2,1}}; 
          
/*
PREDEFINED END
*/


system("cls");

printf("le Taquin :\n");

chooseT: printf("\nchoose a what to do from the menu:\n");
printf("1.use predefined configs\n2.use new config\n3.import from file\nx.return\n");


switch(getch())
{
case '1':
            printf("\nchoose a predefined config:\n");
            printf("1.A\n2.B\n3.C\n4.D\nx.return\n");

            switch(getch())
                {
                  case '1':
                          
                            for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) sys.init.val[i][j]=in1[i][j];
                           break;


                  case '2':
                          
                             for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) sys.init.val[i][j]=in2[i][j];
                           break;
                  case '3':
                           
                             for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) sys.init.val[i][j]=in3[i][j];
                          break;

                    case '4':for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) sys.init.val[i][j]=in4[i][j];
                          break;
                    default : goto chooseT;

                    };goto eXitT;


            break;
case '2':printf("\n add size of Taq(default 3x3)\n");
         printf("n=");
         scanf("%d",&(sys.n));
         printf("m=");
         scanf("%d",&(sys.m));
         printf("\n fill in the lab(%d x %d):[1..%d] for numberz,[0] for space,[88] for exit\n",sys.n,sys.m,sys.n*sys.m-1);
         for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) {printf("[%d,%d]=",i,j);
                                                              rep:  scanf("%d",&(sys.init.val[i][j]));
                                                            if ( sys.init.val[i][j]==88) goto chooseT;
                                                            if (sys.init.val[i][j]>sys.n*sys.m-1 || sys.init.val[i][j]<0) goto rep;
                                                                }
         printf("\n\"le taquin\" filled is:");
           for(char i=0;i<sys.n;i++)
            {printf("\n\t");
                for(char j=0;j<sys.m;j++)
                switch (sys.init.val[i][j])
                {case 0:printf("_ ");break;
                 default:printf("%d ",sys.init.val[i][j]);break;
                
                }
                
                }
       
        printf("\ncompleted...go on!!\n");
        getch();
        goto eXitT;

            break;
case '3':break;
case 'x':goto eXitT;

}

goto chooseT;

eXitT:

system("cls");





BBA(&sys);


if (sys.trouv) printf("found...\n"); else printf("not found...\n");
printf("cpt=%d\n",sys.cpt);
//system("pause");
//afichage
char cpt=0;
for(list *l=sys.solution;l!=NULL;l=l->suiv)
{//system("cls");
 printf("step %d:\n",cpt++);
for(char i=0;i<sys.n;i++)
{printf("\n\t");
for(char j=0;j<sys.m;j++)
switch (l->X.val[i][j])
{case 0:printf("_ ");break;
 default:printf("%d ",l->X.val[i][j]);break;

}

}
printf("\n\n");
//system("pause");


}
char cyn;
do
{
printf("\nare you want to see it in HTML?y/n");
cyn=getch();
}
while (cyn!='y'&&cyn!='n' );
if (cyn=='y') export_Taq(sys.solution,sys.n,sys.m);


};

void Ord()
{
class system sys=init_class_Ord();

char in[1][4]={0,1,0,0};

sys.m=E=4;
sys.n=1;
P=2;
mode[0]=0;mode[1]=0;
Ep[0]=1;Ep[1]=2;
int temp[2][4]={{1,2,1,1},{5,1,1,5}};
int temp2[2][4]={{1,1,1,1},{1,1,1,1}};
for(char i=0;i<sys.n;i++)for(char j=0;j<sys.m;j++) sys.init.val[i][j]=in[i][j];
for(char i=0;i<P;i++)for(char j=0;j<E;j++) Tex[i][j]=temp[i][j];
for(char i=0;i<P;i++)for(char j=0;j<E;j++) Et[i][j]=temp2[i][j];




BBA(&sys);
export_Taq(sys.solution,sys.n,sys.m);
if (sys.trouv) printf("found...\n"); else printf("not found...\n");
printf("cpt=%d\n",sys.cpt);

//afichage
char cpt=0;
for(list *l=sys.solution;l!=NULL;l=l->suiv)
{printf("\nstep %d:\n",cpt++);
for(char i=0;i<sys.n;i++)
{printf("\n\t");
for(char j=0;j<sys.m;j++)
printf("E°%d-->P°%d\t",j,l->X.val[i][j]);

}
}
printf("\n\n");
system("pause");
};








void Pont()
{
class system sys=init_class_Pont();
sys.m=5;
sys.n=1;
int temp[5]={1,3,6,8,12};

for(char j=0;j<sys.m;j++) sys.init.val[0][j]='R';
sys.init.val[0][sys.m]='n';
for(char j=0;j<sys.m;j++) TIME[j]=temp[j];




BBA(&sys);
export_Pont(sys.solution,sys.n,sys.m);
if (sys.trouv) printf("found...\n"); else printf("not found...\n");
printf("cpt=%d\n",sys.cpt);

//afichage
char cpt=0;
for(list *l=sys.solution;l!=NULL;l=l->suiv)
{printf("\nstep %d:\n",cpt++);
for(char i=0;i<sys.n;i++)
{printf("\n\t");
for(char j=0;j<sys.m;j++)
printf("%d:%c\t",j,l->X.val[i][j]);

}
}
printf("\n\n");

};

 main(int argc, char *argv[])
{
    
system("cls");
printf("The application of A* in GAMES:\n");

choose: printf("\nchoose a game from the menu:\n");
printf("1.Labyrinth\n2.Pont\n3.Taquin\nx.quit\n");

switch(getch())
{
case '1':Lab();break;
case '2':Pont();break;
case '3':Taq();break;
case 'x':goto eXit;

}
getchar();
goto choose;






    
    
eXit:    system("PAUSE");
    return EXIT_SUCCESS;
}
