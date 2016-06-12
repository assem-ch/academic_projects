#include <iostream>

struct Point { int x,y; };
int main() {
    int N; Point P,Q;
    std::cin >> N;
    for(int i = 0; i<N; i++) {
        std::cin >> P.x >> P.y >> Q.x >> Q.y;
        std::cout << 2*Q.x - P.x  <<" "<< 2*Q.y- P.y<<"\n";
    }
    return 0;
}
