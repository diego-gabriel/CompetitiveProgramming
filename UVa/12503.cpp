#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void exec(int &x, string &cad){
	if(cad[0] == 'R')
		x++;
	if(cad[0] == 'L')
		x--;
}

int main(){
	int test;
	cin>>test;
	int n;
	while (test--){
		cin>>n;
		int x = 0;	
		vector <string> ins;
		string cad;
		int v;
		for (int i = 0; i < n; i++){
			cin>>cad;

			if (cad[0] == 'S'){
				cin>>cad>>v;
				exec(x, ins[v-1]);
				ins.push_back(ins[v-1]);
			}
			else{
				exec(x, cad);
				ins.push_back(cad);
			}

		}

		cout<<x<<endl;
	}
	return 0;
}