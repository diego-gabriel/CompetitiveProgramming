#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;
	for (int test = 1; test <= nTest; test++){
		int n, m;
		cin>>n>>m;
		int num[n];
		for(int i = 0; i < n; i++)
			cin>>num[i];
		sort(num, num+n);
		int difs[n-1];
		for (int i = 1; i < n; i++){
			difs[i-1] = num[i]-num[i-1];
		}
		sort(difs, difs+(n-1));
		int tot = 0;

		for (int i = 0; i < n-m; i++)
			tot += difs[i];

		cout<<"Case #"<<test<<": "<<tot<<endl;
	}
	return 0;
}