#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int V, n, a;
    cin >> V;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if (a == V) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
