
#include <stdio.h>
#include <stdlib.h>


#define MAXLINE 128
#define MAXVECTOR 100

typedef struct node node;

struct node { 
	int val;
	node* next;
	}; 


 



int mypow(int a,int b) { int p=1; for (int i=0;i<b;i++) p*=a; return p; };
int length(int x) 
{ 

int i=0; for (i=0;x!=0;x/=10) {i+=1;}; return i; };
int recycle(int x,int length) { return x/10 + x%10 * mypow(10,length-1); }; 
int est_deja_vu(int val,node* list) { 
	int e=0; 
	for (node* p=list; p!=NULL;p=p->next) 
		{
		if (p->val==val) {
					e=1;
					break;
				}
		}
	//printf("%%deja_vu(%d)=%d",val,e);
	return e;

	}

int main()
{
char line[MAXLINE];
FILE* input=fopen("in","r");
FILE* output=fopen("out","w");
fgets(line,MAXLINE,input);
int T=atoi(line);
printf("T=%d \n",T);

for (int i=0;i<T;i++)
{	

	unsigned int A,B,cpt=0;
	char case_param[MAXLINE];
	fgets(case_param,MAXLINE,input);
	sscanf(case_param,"%d %d",&A,&B);
	int leng=length(A);
	printf("Case=%d (A=%d,B=%d) leng=%d\n",i,A,B,leng);
	

	for(int n=A;n<=B;n++)
		{
			node* deja_vu_list;
			node* q;
			deja_vu_list=NULL;
			q=NULL;
			int temp=n,m;
			//printf(">>\tn=%d => ",n);
			for (int k=0;k<leng;k++)
				{
				m=recycle(temp,leng);
				//printf("%d,",m);
				temp=m;
				int jamais_vu=!est_deja_vu(m,deja_vu_list);
				if (m>n && m<=B && jamais_vu) cpt++;
				
				if (jamais_vu)
					{
						node* p= (node* ) malloc (1);
						p->val=m;
						p->next=NULL;
						if (q) q->next=p;
						else deja_vu_list=p;
						q=p;
					};
				}
			//printf("\n");

		}
			
		
	fprintf(output,"Case #%d: %d\n",i+1,cpt);
	}

fclose(input);
fclose(output);

printf("done!");

return 0;

}
