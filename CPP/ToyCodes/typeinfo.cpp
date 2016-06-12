#include <iostream>
#include <typeinfo>

int main(){
char *a;

std::cout << typeid(a).name() << '\n';


return 0;

}

