#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    long N,x,y,z,s;
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> N;
        x=2;
        y=1;
        s=0;
        while(x <= N){
            if (x%2==0) s+=x;
            z = x;
            x = y+x;
            y = z;
        }
        cout<<s<<"\n";
    }
    return 0;
}
