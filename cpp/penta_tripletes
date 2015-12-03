#include <iostream>
#include <math.h>
 
using namespace std;
 
int main() {
 
int a,b,c,s=1;
 
for (a = 1; a < 1000 && s; a++ ) {
   for ( b = a+1; b < 1000 - a  && s; b++ ) {
    s = 1;
    c = 1000 - a - b;
    if ( c < b ) break;
    
    if ( a*a + b*b  == c*c ) {
        cout<<a<<"+"<<b<<"+"<<c<<"="<<a+b+c<<"\n";
        s = 0;
        break;
    }
 
 
}
 
 
} 