#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;

	while (nTest--){
		int d;
		cin>>d;
		cin.ignore();
		string cad;
		getline(cin, cad);
		int n;
		cin>>n;
		int t = cad.length();
		int p = 0;
		int f;
		cout<<d<<" ";
		for (int i = 0; i < n; i++){
			cin>>f;
			p = p + t + f;
			p = p % t;
			cout<<cad[p];
		}
		cout<<endl;
	}
	return 0;
}