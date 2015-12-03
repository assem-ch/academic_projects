#include <iostream>


using namespace std;



int main() {


long GS=0;

for(int i=10; i<1000000; i++) {
//cout<<"\n"<<i<<"=";
long S=0;

for(long j=i; j!=0; j = j/10){

short d = j % 10;
S += d * d * d * d * d;

//cout<<"+"<<d;

if (S>i) break;

}

//cout<<S;

if (S == i) {
		GS+=S;
		cout<<i<<"<<<==========================\n"; 
		}

}


cout<<"Sum=="<<GS;

return 0;

}
