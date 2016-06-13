
#include <iostream>

//typedef struct element element;
using namespace std;

struct element {
			char val;
			element *next;
};


int main() {




	char c=0;
	tab[i] = 0; 
	element *q=0;
	cout<<"\nline"<<i<<"\n";
	while(c!='x') {
			cin>>c;
			cout<<"*";
			element *e = new element;
			e->val = c;
			e->next= 0; // NULL			
		    	if (q) q->next = e;
			else tab[i] = e;
			q=e;
			}
	


for(int i = 0; i<10; i++) {
	cout<<"\nline "<<i<<"\n";
	for(element *e = tab[i]; e!=0; e=e->next) 
		{
		    cout<<"\t"<<e->val;
		}		
	}

return 0;
}
