#include <cstdlib>
#include <iostream>

#define tab_max_x 3
#define tab_max_y 3





//changer enfiler pour test les ouvert  






using namespace std;

/*types and structures*/
typedef struct config config;
typedef struct list list;

struct bi {     
char x;
char y;

};
struct config{
char val[tab_max_x][tab_max_y];

};
 struct list {
            config X;
            float f;
            float g;
            list *suiv;
            list *prev;
           // float hash;
            };
          
            
struct file {
            list *l;
            file *suiv;
            };
			
/*class general d'entree d'entree*/
class system 
            { public:
                system()
					{cpt=0;
					trouv=false;
					solution=NULL;
					n=1;
					m=1;
					}
				bool trouv;
                char n,m;
                config init;
                bool (*but)(config A,int n,int m);
                float (*p)(config A,int n,int m);
                float (*h)(config A,int n,int m);
                list *(*SUCC)(config A,int n,int m);
                list *solution;
                int cpt;
				
                
            };			
			
/*declaration functions*/			
bool eqiv(config A,config B,char n,char m);
//bool copylist(list *A,list **B);
list *inverser(list *A);
bool detruire(list **A);
bool inserer(list **Z,config X0,char n,char m);
bool search(list *Z,config X0,char n,char m);

bi SchConf(config A,char n,char m,char val); 
bool enfiler(file **F,list *l/*,char n,char m*/);
list *defiler(file **F);
float Hash(config Y,int n,int m);

/*implementation*/ 
/*float Hash(config Y,int n,int m)
{float hash=0;
        for(int i=0;i<n;i++)
         for(char j=0;j<m;j++)
        {hash+=Y.val[i][j]*i*j;};
return hash;
}*/

 
bool eqiv(config A,config B,char n,char m) {char i;
                                                      for(i=0;i<n;i++)
                                                      for(char j=0;j<m;j++)
                                                       {if (A.val[i][j]!=B.val[i][j]) goto fin_eqiv;
                                                                 
                                                                }
                                                             
                                                     fin_eqiv:if (i==n) return true; else return false;    
                                                             };    
        

/*list lineare de configs*/
/*bool copylist(list *A,list **B){
list *p=A,*l=NULL,*m=NULL;
while(p!=NULL) {    m=l;
                    l=new list;
                    l->X=p->X;
                    l->suiv=NULL;
                    if (m==NULL) *B=l; 
                    else m->suiv=l;
                    p=p->suiv;
                }



return true;
}*/

list *inverser(list *A){
list *p=A,*l=NULL,*B=NULL;

while(p!=NULL) { l=B;
                    B=new list;
                    B->X=p->X;
                    B->suiv=l;
                    p=p->prev;
                }

return B;
}

bool detruire(list **A){list *p=NULL;
while (*A!=NULL){p=*A;*A=(**A).suiv;delete p;}
return true;
}

bool inserer(list **Z,config X0,char n,char m){
                                list *p=new list;
                                        p->X=X0;
                                   
                                        p->suiv=*Z;
                                        *Z=p;
                                                          
                                    return true;
                                    }
bool search(list *Z,config X0,char n,char m) {
                                list *p=Z;
                                //float hX0=Hash(X0,n,m);
                                bool trouv=false;
                                while (p!=NULL && !trouv) {/*if (p->hash==hX0)*/ if (eqiv(p->X,X0,n,m)) trouv=true;p=p->suiv;}
                                  return trouv;                                        
                                    }  ;




bi SchConf(config A,char n,char m,char val) {char i;char j;
                                            for(i=0;i<n;i++)
                                            for(j=0;j<m;j++){
                                                    if (A.val[i][j]==val) goto fin;
                                                                }
                                            fin:
                                            bi b;    
                                            b.x=i;
                                            b.y=j;
                                            return b;
                                            }

/*File avec priorite*/
bool enfiler(file **F,list *l,char n,char m){                                 
                                file *p=*F,*q=NULL;
                                bool its_prio=false;
                                while (p!=NULL && !its_prio) {
                                                               if (p->l->f>l->f) {its_prio=true;};
                                                               q=p;
                                                               p=p->suiv;
                                                                }
                               
                               
                               

                                if (q==NULL) {*F=new file;
                                              (**F).l=l;
                                                
                                               (**F).suiv=p;
                                               q=*F;
                                                }
                                else {file *n=new file;
                                        n->l=l;
                                        n->suiv=p;
                                        q->suiv=n;
                                         q=n;   
                                        }
                                 file *q0=q;
                                bool trouv=false;
                                 while (p!=NULL && !trouv) {if (eqiv(l->X,p->l->X,n,m)) {q->suiv=p->suiv;
                                                                                               p->l->f=l->f;
                                                                                               p->l->g=l->g;
                                                                                               p->l->prev=l->prev;
                                                                                               q0->l=p->l; 
                                                                                                trouv=true;};
                                                    q=p;
                                                    p=p->suiv;
                                                };

                               
                                    return true;

};
list *defiler(file **F){list  *l=NULL;
                        if (F!=NULL) {l=(**F).l;*F=(**F).suiv;}
                        return l;        
                        };


 /////////////////////////////////////A*
bool BBA(class system  *system){
 file *F=NULL;
 
 config X;
        char n=system->n;
        char m=system->m;
 //config but=system->but;

 list *T=NULL,*Z=new list,*Ferm=new list,*last=NULL;
        
 
        Ferm->X=system->init;
        Ferm->suiv=NULL;
        int cpt=0;
      
        Z->X=system->init;
        Z->prev=NULL;
        Z->suiv=NULL;

       Z->f=system->h(Z->X,n,m)+system->p(Z->X,n,m);
       Z->g=system->p(Z->X,n,m);
       
enfiler(&F,Z,system->n,system->m);

bool trouv=false;
while (F!=NULL && !trouv) 
            {Z=defiler(&F);printf("%d\t",cpt++);
             X=Z->X;
            float g=Z->g; 
            if (!(system->but(X,system->n,system->m)))
                    {
                       for(list *l=system->SUCC(X,n,m);l!=NULL;l=l->suiv)
                        {config Y=l->X;
                         if (!search(Ferm,Y,system->n,system->m))
                                                 {  inserer(&Ferm,Y,0,0);
                                                    T=new list;
                                                    T->suiv=NULL;
                                                    T->prev=Z;
                                                    T->X=Y;
                                                    T->f=system->h(Y,n,m)+system->p(Y,n,m)+g;
                                                    T->g=system->p(Y,n,m)+g;    
                                                                                             
                                                    enfiler(&F,T,system->n,system->m);
                                                  }     
                                  }
                    //detruire(&last);
                    last=Z;
                }
            else trouv=true;
      


            }
    system->solution=inverser(Z);//to change
    system->trouv=trouv;    
    return trouv;
};       



