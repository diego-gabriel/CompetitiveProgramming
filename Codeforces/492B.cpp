#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, l;
	cin>>n>>l;
	int a[n];
	for (int i = 0; i < n; i++)
		cin>>a[i];

	sort(a, a+n);

	int m = 2*max(a[0], l-a[n-1]);

	for (int i = 1; i < n; i++){
		m = max(m, a[i] - a[i-1]);
	}

	cout<<m/2;
	if (m%2)
		cout<<".5000000000";
	else cout<<".0000000000";
	cout<<endl;

	return 0;
}