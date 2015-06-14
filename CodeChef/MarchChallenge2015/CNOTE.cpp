#include <iostream>

using namespace std;


int main(){

	int x, y, k, n;
	int t;
	cin>>t;
	while (t--){
		cin>>x>>y>>k>>n;
		int need = x - y;
		int p, v;
		bool ok = false;
		for (int i = 0; i < n; i++){
			cin>>p>>v;
			ok = ok || (p >= need && v <= k);
		}

		if (ok)
			cout<<"LuckyChef"<<endl;
		else
			cout<<"UnluckyChef"<<endl;
	}

	return 0;
}