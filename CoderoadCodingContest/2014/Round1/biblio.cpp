#include <bits/stdc++.h>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 0; test < nTest; test++){
		int p, m, c;
		cin>>p>>c>>m;
		cout<<"Caso #"<<test+1<<": ";
		cout<<solve(p, c, m)<<endl;
	}

	return 0;
}