#include <stdio.h>
#include <stdlib.h>

typedef struct tree tree;
typedef struct list list;

struct tree {
tree *left, *right;
int val;
int cumul;
};

struct list {
tree *p;

list *next;
int prio;
};




int Explore(tree *T, int max) {
  int max0=max,val1, val2;
 if (T) {
           //if (!T->left && !T->right) 
           printf("%d ==> %d\n", T->val, T->cumul);
           if (T->cumul> max) max0 = T->cumul;
           
           val1 = Explore(T->left, max0);
           val2 = Explore(T->right, max0);

           if (val1>val2) max0= val1;
        else max0 = val2;
        return max0;
    
    }
 else return max0;
}

int max(int values[][15], int i, int j) {
 
    int max_down, max1, max2;

    max1 = max(values, i+1, j);
    max2 = max(values, i+1, j+1);

    if (max1<max2) max_down = max2;
    else max_down = max1;

    return values[i][j] + max_down;


}



int main() {

int T, N;


printf("1");
scanf("%d", &T);

for(int z=0; z < T; z++){
scanf("%d", &N);
int i,j,x;
int values[15][15];

tree *T = 0, *tempT = 0, *tempT2 = 0;
list *P = 0, *Q=0, *Last=0, *tempL = 0;
int alter=0;

for(i=0; i<N; i++) {
Q = P; P = 0; Last = 0; alter = 0; 
for(j=0; j<=i; j++) {
scanf("%d",&x);

values[i][j] = x;

tempT = (struct tree*) malloc( sizeof( struct tree ) ); 
tempT->left = 0;
tempT->right = 0;
tempT->val = x;
tempT->cumul = x;

tempL =  (struct list*) malloc( sizeof( struct list ) );
tempL->p = tempT;
tempL->next = 0;

if (P) Last->next = tempL;
else P = tempL;
Last = tempL;

if (!T) T=tempT;
else {
     if (!alter) {
            tempT->cumul = tempT->val + Q->p->cumul;
            Q->p->left = tempT;
            alter = 1;
        }
     else { tempT->cumul = tempT->val + Q->p->cumul;
        Q->p->right = tempT;
        Q = Q->next;
        if (Q) {

            tempT2 = (struct tree*) malloc( sizeof( struct tree ) );
            tempT2->left = 0;
            tempT2->right = 0;
            tempT2->val = x ;
            tempT2->cumul = x + Q->p->cumul;
            Q->p->left = tempT2;

            }
        }
    }
};
};

int max0 = max(values, 0, 0); //Explore(T, 0);

printf("%d\n", max0);

P =  (struct list*) malloc( sizeof( struct list ) );
P->p = T;
P->prio = T->val;
P->next = 0;


}

return 0;
}