#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int a[n];
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	int r, d;
	char k;
	r = 0;
	for (int i = 0; i < m; i++){
		cin>>k>>d;
		if (k == 'C')
			r = (r + d + n) % n;
		if (k == 'A')
			r = (r - d + n) % n;
		if (k == 'R')
			cout<<a[(d+r-1+n) % n]<<endl;
	}
}