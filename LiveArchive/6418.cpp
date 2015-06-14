#include <iostream>

using namespace std;

int main(){
	bool fst = true;
	int a, b, m;
	while (cin>>a){
		if (a== -1) break;
		cin>>b>>m;
		int i;
		for (i = m; b%i != a%i; i--){

		}
		cout<<i<<endl;
	}
	return 0;
}