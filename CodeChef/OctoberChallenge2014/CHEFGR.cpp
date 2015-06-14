#include <iostream>

using namespace std;

int main(){
	int t, n;
	cin>>t;

	while (t--){
		int m;
		cin>>n>>m;
		int a[n];
		int x = 0;
		for (int i = 0; i < n; i++){
			cin>>a[i];
			x = a[i] > x ? a[i] : x;
		}

		int s = 0;
		for(int i = 0; i < n; i++)
			s += (x-a[i]);

		m -= s;

		if (m % n == 0)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

}