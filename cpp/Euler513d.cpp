#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>

#include <time.h>

#define N 10
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main(){
    clock_t begin, end;
    double time_spent;
    int a,b,mc,C;
    long count,x,y;


    begin = clock();

    map< long, vector< pair< int, int > > > right;

    for(a = 1; a<= N; a++){
        for(b =a; b <= N; b+=2){
            x = 2* (a * a + b * b);
            if (right.find(x) == right.end())
                right[x].insert(right.begin(), make_pair(a,b));
            else {
                vector< pair< int, int > >  new_vector(make_pair(a,b));
                right[x] = new_vector;
            }
        }
    }

    count = 0;

    for(mc =1; mc < (int)((sqrt(3)/2) *N)+1; mc++){
        for(C = 1; C < N/2+1; C++){
            y = 4 * (mc * mc + C * C);
            if (right.find(y) == right.end()) 
                for(int i=0; i < right[y].size(); i++) {
                    a = right[y][i].first;
                    b = right[y][i].second;
                    if ((b <= C*2) && (C*2 < a+b)) count++;
                }
        }
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\ncount == %lu with %f\n", count, time_spent);
    
    return 0;

}