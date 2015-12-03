#include <iostream>
#include <cmath>

using namespace std;




int main()
{

int i=2,number=1,div_nb;


while(true) {
number +=i;

div_nb=2; // we start with 2 so 1 and number is always considered divisors
for(int k=2;k<=sqrt(number);k++){
	if ( number%k == 0 ) {
			if (k!=number/k) div_nb+=2;
			else div_nb+=1;
			}
}

cout<<number<<"==>"<<div_nb<<"\n";

if (div_nb>500) break;

i++;
}

}
