#include <iostream>
 
using namespace std;
 
#define OBJECTIVE 100001
 
struct element {
    int val;
    element *next;
};
 
 
int main() {
 
int cpt = 0;
int number = 2;
element *List=0, *Last=0;
int is_prime=1;
 
 
while(cpt != OBJECTIVE ){
    //cout<<"number ==> "<<number<<"\n";
    is_prime=1;
    for (element *P=List; P!=0 && is_prime; P = P->next) {
        if ( number%P->val==0) is_prime=0;
    }
    if (is_prime) {
             element *N = new element;
             N->val = number; N->next = 0;
            if (Last) Last->next = N;
            else  List = N;
            Last = N;
            //cout<<"#### prime ####"<<"\n";
            //last_prime = number;
            cpt ++;
            }
    number ++;
}
 
cout<<">>"<<Last->val;
 
return 0;
 
}