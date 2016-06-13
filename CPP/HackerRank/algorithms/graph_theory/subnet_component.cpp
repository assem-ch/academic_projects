#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

typedef unsigned long long ULL;

int n;
ULL d[30];

int p[65], r[65];
vector <int> v[30];

int find(int x) {
   //if ( p[x] != x ) ****FILL THE MISSING LINE HERE****
   return p[x];
}
void link(int x, int y) {
   if ( r[x]  < r[y] ) r[x]++;
   if ( r[x] == r[y] ) p[x] = p[y]; else p[y] = p[x];
}


int f(int x) {
   int ret = 0;
   if ( x == n ) {
      bool flag[65] = {false};
      REP(j,64) flag[find(j)] = true;
      REP(j,64) ret += flag[j];
      return ret;
   }
   int tp[65], tr[65];

   memcpy(tp,p,sizeof(p));
   memcpy(tr,r,sizeof(r));

   ret += f(x+1);

   memcpy(p,tp,sizeof(p));
   memcpy(r,tr,sizeof(r));

   FOR(j,1,v[x].size()-1)
      link(find(v[x][j]),find(v[x][0]));

   ret += f(x+1);


   return ret;
}


int main()
{
   cin >> n;
   REP(i,n) cin >> d[i];

   REP(i,n) REP(j,64) if ( (d[i] >> j) & 1 ) v[i].push_back(j);

   REP(j,64) p[j] = j, r[j] = 0;
   cout << f(0) << endl;

   return 0;
}