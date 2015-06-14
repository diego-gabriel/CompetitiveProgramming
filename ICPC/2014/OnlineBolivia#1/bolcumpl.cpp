#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int n, m, t;
	cin>>t;

	while (t--){
		cin>>n>>m;
		int val[n];

		for (int i = 0; i < n; i++)
			cin>>val[i];

		sort(val, val+n);

		int i = 0;
		while (i < n && m >= 0){
			m -= val[i];
			i++;
		}
		cout<<i-1<<endl;

	}
	return 0;
}