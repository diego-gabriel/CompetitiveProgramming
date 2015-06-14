#include <iostream>

using namespace std;

int main(){
	int test;
	cin>>test;

	while (test--){
		int n, k, v, p;
		cin>>n>>k;
		p = 0;
		for (int i = 0; i < n; i++){
			cin>>v;
			if (v%2 == 0) p++;
		}

		if (p >= k && (k != 0 || p < n))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}