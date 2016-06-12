#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    int down = (int)ceil(pow(10, (N-1.0)/N));
    int up = 10;

    for(int d=down; d < up; d++){
        cout<<(long long)pow((long double)d,(long double)N)<<endl;
    }
    return 0;
}
