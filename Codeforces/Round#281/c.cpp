#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int points(int n, int i){
	return (n-i)*3 + i*2;
}

int main(){
	int n;
	int m;
	int v;
	cin>>n;
	vector <int> a, b;

	for (int i = 0; i < n; i++){
		cin>>v;
		a.push_back(v);
	}
	cin>>m;
	for (int i = 0; i < m; i++){
		cin>>v;
		b.push_back(v);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ia, ib, d, dif, ba, bb;
	ia = 0;
	ib = 0;
	dif = 0x80000000;
	d = 0;

	for (ia = 0; ia < n; ia++){
		while (ib < m && b[ib] < a[ia])
			ib++;

		if (points(n, ia) - points(m, ib) > dif){
			dif = points(n, ia) - points(m, ib);
			ba = points(n, ia);
			bb = points(m, ib);
		}
	}

	cout<<ba<<":"<<bb<<endl;

	return 0;
}