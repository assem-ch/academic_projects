#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1000000007, MAXN = 1005;

int binom[MAXN][MAXN];

int N, K;
int X[MAXN], Y[MAXN];
int Xmin, Xmax, Ymin, Ymax;
pair<int, int> dude[4];

inline int calc(vector<pair<int, int> > vec) {
   int num = 0;
   for(int i = 0 ; i < N ; i++) {
      for(int j = 0 ; j < (int)vec.size() ; j++) {
         if (vec[j].first == 0 && X[i] == vec[j].second) {
            num++;
            break;
         }   else if (vec[j].first == 1 && Y[i] == vec[j].second) {
            num++;
            break;
         }
      }
   }
   if (num > K) {
      return 0;
   }   else {
      return binom[N - num][K - num];
   }
}

int main() {
   scanf("%d %d", &N, &K);
   binom[0][0] = 1;
   for(int i = 1 ; i <= N ; i++) {
      binom[i][0] = 1;
      for(int j = 1 ; j <= i ; j++) {
         binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
      }
   }

   for(int i = 0 ; i < N ; i++) {
      scanf("%d %d", &X[i], &Y[i]);
   }
   Xmin = X[0];
   Xmax = X[0];
   Ymin = Y[0];
   Ymax = Y[1];
   for(int i = 1 ; i < N ; i++) {
      Xmin = min(Xmin, X[i]);
      Xmax = max(Xmax, X[i]);
      Ymin = min(Ymin, Y[i]);
      Ymax = max(Ymax, Y[i]);
   }
   dude[0] = make_pair(0, Xmin);
   dude[1] = make_pair(0, Xmax);
   dude[2] = make_pair(1, Ymin);
   dude[3] = make_pair(1, Ymax);
   int ans = 0;
   for(int mask = 1 ; mask < 16 ; mask++) {
      int sgn = __builtin_popcount(mask);
      vector<pair<int,int> > v;
      for(int i = 0 ; i < 4 ; i++) {
         if ((mask >> i) & 1) {
            v.push_back(dude[i]);
         }
      }
      if (sgn & 1) {
         ans = (ans + calc(v)) % MOD;
      }   else {
         ans = (ans - calc(v)) % MOD;
      }
   }
   ans = (ans + MOD) % MOD;
   ans = (ans + MOD) % MOD;
   printf("%d\n", ans);
   return 0;
}
