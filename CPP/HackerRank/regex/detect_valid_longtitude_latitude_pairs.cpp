#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

bool IsValid(string &s) {
    stringstream ss(s);
    if (ss.get() != '(')
        return false;
    double x, y;
    ss >> x;
    if (ss.get() != ',')
        return false;
    ss >> y;
    if (x>90 || x < -90 || y > 180 || y < -180) return false;
    if (s.find(".,") != string::npos || s.find(".)") != string::npos)
        return false;
    if (s.find("-0") != string::npos && s.find("-0.") == string::npos)
        return false;
    if (s.find("(0") != string::npos && s.find("(0.") == string::npos)
        return false;
    if (s.find(" 0") != string::npos && s.find(" 0.") == string::npos)
        return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string l;
        cin >> ws;
        getline(cin, l);
        if (IsValid(l))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    return 0;
}
