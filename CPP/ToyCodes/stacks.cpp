#include <iostream>
#include <stack>

using namespace std;





int main(){

stack<int> names ;

names.push(1);
names.push(2);
names.push(3);

cout<<names.top();
names.pop();
cout<<names.top();
names.pop();
cout<<names.top();
names.pop();

return 0;

}
