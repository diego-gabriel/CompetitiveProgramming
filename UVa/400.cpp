#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string build(int n, char k){
	string res = "";

	while (n--){
		res = res + k;
	}

	return res;
}

int main(){
	int n;
	while (cin>>n){
		vector<string> list;
		string name;
		int longest = 0;
		for (int i = 0; i < n; i++){
			cin>>name;
			list.push_back(name);

			if (longest < name.length()){
				longest = name.length();
			}
		}
		sort(list.begin(), list.end());
		cout<<build(60, '-')<<endl;

		int nCols = 62/(longest+2);
		int nRows = (n+nCols-1)/nCols;

		for (int i = 0; i < nRows; i++){
			for (int j = i, nc = 1; nc <= nCols; j+=nRows, nc++){
				int len;
				if (nc == nCols)
					len = longest;
				else
					len = longest+2;
				string cad;
				if (j >= n)
					cad = "";
				else
					cad = list[j];
				cout<<cad<<build(len-cad.length(), ' ');
			}
			cout<<endl;
		}

	}
	return 0;
}