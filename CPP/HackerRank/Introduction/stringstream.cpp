#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   stringstream ss(str);
   int a;
   char ch=',';
   vector<int> out;

       while(ss >> a){

       out.insert(out.end(), a);

           ss >> ch;
       }

   return out ;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}