#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int main(){
	int test;
	cin>>test;
	map <string, int> c;
	while (test--){
		string cad, c2;
		cin>>cad;
		int n = cad.length()+1;
		cad = " "+cad;
		vector <vector<int> > memo;
		memo.assign(n, vector<int>(n, 0));

		int res = 0;
		for (int i = 1; i < n; i++){
			for(int j = i+1; j < n; j++){
				if (cad[j] == cad[i]){
					memo[i][j] = memo[i-1][j-1]+1;
					res = res > memo[i][j] ? res : memo[i][j]; 
				}
			}
		}

		cout<<res<<endl;

	}
	return 0;
}