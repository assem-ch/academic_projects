#include <iostream>
#include <string>
using namespace std;

int main() {
   string a,b,ap, bp;
    cin >> a >> b;
    cout << a.size()<<" "<< b.size() << endl;
    cout << a + b << endl;
    char swap;
    swap = a[0];
    a[0] = b[0];
    b[0] = swap;
    cout << a << " "<< b << endl;
    return 0;
}
