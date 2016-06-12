#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{

int T, N, MAX_N=0, R[10];

cin >> T;

vector< pair <int, int> > Ns;
for(int z = 0; z < T; z++){
                             cin >> N;
                             MAX_N = max(N, MAX_N);
                             Ns.insert(Ns.begin(),  make_pair(N, z));
                        }
int i=2,number=1,div_nb;


while(true) {
number +=i;

int new_number = number;
div_nb=1;
  for (int k = 2; k <= new_number; k++)
  {
    int exponent = 0;
    while (new_number % k == 0) {
        exponent++;
        new_number /= k;
    }
    div_nb *= (exponent+1);
  }

for (vector<pair<int,int>>::iterator it = Ns.begin(); it != Ns.end();){
    if (div_nb > (*it).first){
        R[(*it).second] = number;
        it = Ns.erase(it);
    }
    else  it++;
}

if (div_nb>MAX_N) break;

i++;
}

for(int z = 0; z < T; z++){
    cout << R[z]<<endl;
}

return 0;
}
