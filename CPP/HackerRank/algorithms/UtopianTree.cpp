#include <iostream>
#include <math.h>

using namespace std;

int height(int n) {
    if (n==0) return 1;
    if (n%2) return pow(2,(n+3)/2)-2 ;
    else return pow(2, (n+2)/2)-1;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
