#include <iostream>
#include <sstream>
#include <fstream> 
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>


using namespace std;



class Config
{
public:
vector< vector<char> > cells;
int nb_zeros; 
int R;
int C;
int M;
vector<tuple<int,int> > unexplored;
};


bool Compare(Config config1, Config config2)
     {
         return config1->unexplored.size()>config2->unexplored.size();
    };

int main() {

ifstream in;
ofstream out;

int T,R,C,M;


in.open( "in", ios_base::in );
out.open( "out", ios_base::out );

if (!in) cerr << "no input file!!!";

in >> T;
char NewLine;
in >> NewLine;
for(int cpt=1; cpt<=T; cpt++) {	
	in >> R >> C >> M >> NewLine;
	priority_queue<Config, vector<Config>, function<bool(Config,Config)> > pq(Compare);
	
	Config init ;
	init.nb_zeros=0;
	init.R = R;
	init.C = C;
	init.M = M;
	for (int i=0; i < R; i++)
	    {
		vector<char> v;
		for (int j=0; j<C; j++) {
		 v.push_back('.');
		}
	     init.cells.push_back(v);
	}
		

	out << "Case #" << cpt << "\n";

}


return 0;

}





