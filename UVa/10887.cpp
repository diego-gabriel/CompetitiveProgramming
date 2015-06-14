#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;
	for (int test = 1; test <= nTest; test++){
		int n, m;
		cin>>n>>m;
		string a[n], b[m];
		cin.ignore();
		for (int i = 0; i < n; i++)
			getline(cin, a[i]);
		for (int i = 0; i < m; i++)
			getline(cin, b[i]);

		set<string> s;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				s.insert(a[j] + b[i]);
			}
		}

		cout<<"Case "<<test<<": "<<s.size()<<endl;
	}	
	return 0;
}