#include <iostream>
#include <sstream>
#include <fstream> 
#include <string>
#include <deque>
#include <algorithm>


#define MAX_VALUE 1

using namespace std;


bool mygreater (int i,int j) { return (i>j); }

int main() {

ifstream in;
ofstream out;

int T,N;


in.open( "in", ios_base::in );
out.open( "out", ios_base::out );

if (!in) cerr << "no input file!!!";

in >> T;
char NewLine;
in >> NewLine;
for(int cpt=1; cpt<=T; cpt++) {
	
	string s;
	getline(in,s);
	istringstream LineN(s);
	LineN >> N;
	float num;
	deque<float> MassNaomi, MassKen;
	getline(in, s);
	stringstream LineNaomi(s);
	while (LineNaomi >> num) MassNaomi.push_back(num);
	getline(in, s);
	stringstream LineKen(s);
	while (LineKen >> num) MassKen.push_back(num);
	//cout<<MassKen[0]<<"\n";

	// WAR
	int war=0;
	deque<float> MassNaomiWar = MassNaomi, MassKenWar = MassKen;
	while (!MassNaomiWar.empty())
  	{	
    		 float ChosenNaomi = MassNaomiWar.back();
		 float LessGreaterVal=MAX_VALUE, Min = MAX_VALUE;
		 int LessGreaterPos, MinPos;
		 for(int i=0;i<MassKenWar.size(); i++){
		   if (MassKenWar[i]>ChosenNaomi &&  MassKenWar[i]<LessGreaterVal) {
			 LessGreaterVal = MassKenWar[i];
			 LessGreaterPos = i;
			};
		   if (Min > MassKenWar[i]) {
			Min =  MassKenWar[i];
			MinPos = i;
			}
		 }

		 int ChosenKen=LessGreaterPos; 
		 if ( LessGreaterVal == 1 || LessGreaterVal < ChosenNaomi) {
		       war ++ ;
		       ChosenKen = MinPos;
		//	cout<<"won";

		 }
		 //cout<<Min<<"\t"<<ChosenKen<<"\t"<<LessGreaterVal<<"\t"<<ChosenNaomi<<"@\n";
		 MassKenWar.erase(MassKenWar.begin()+ChosenKen);
		 MassNaomiWar.pop_back();
  		 	
	}

	
	// The war li ...
	int dwar=0;
	deque<float> MassNaomiDWar = MassNaomi, MassKenDWar = MassKen;
	sort (MassNaomiDWar.begin(), MassNaomiDWar.end());
	sort (MassKenDWar.begin(), MassKenDWar.end());
	//reve:rse(MassKenDWar.begin(), MassKenDWar.end());
	for(int i=0; i< MassNaomiDWar.size(); i++){
	    float ChosenNaomi = MassNaomiDWar[i];
	    if (ChosenNaomi > MassKenDWar.front() && MassKenDWar.back()!=1) {
			dwar++;
		//	cout << "won ==>";
			MassKenDWar.pop_front();
			}
	   else {
		MassKenDWar.pop_back();
		//cout << "lost ==>";	
	    }
	    //cout<<ChosenNaomi<<"\t"<<"\n";
	}
		
	out << "Case #" << cpt << ": " << dwar << " " << war << "\n";

}


return 0;

}





