#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long int r,c;
    cin >> r >> c;
    cout << r/2 + 9 * ((r-1)/2)+ 2*(c-1);
    return 0;
}