#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,a[1000];
    cin>>N;
    for (int k=0; k<N; k++) cin>>a[k];
    for (int k=N-1; k>0; k--) cout<<a[k]<<" ";
    cout<<a[0];
    return 0;
}