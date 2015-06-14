#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string cad;
	int test = 0;
	while(cin>>cad){
		int c = 0;
		int memo[cad.length()];
		memo[0] = 0;
		for (int i = 1; i < cad.length(); i++){
			if (cad[i] != cad[i-1])
				c++;
			memo[i] = c;
		}

		int n, i, j;
		cin>>n;	
		test++;
		cout<<"Case "<<test<<":"<<endl;
		for (int k = 0; k < n; k++){
			cin>>i>>j;
			if (i > j)
				swap(i, j);
			if (memo[i] == memo[j])
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}