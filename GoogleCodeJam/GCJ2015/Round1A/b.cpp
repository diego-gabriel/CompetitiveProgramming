#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

long long sum(long long x, const vector<long long> &m){
	long long res = 0;
	bool flag = false;
	for (int i = 0; i < m.size(); i++){
	//	cout<<x<<"/"<<m[i]<<" adding "<<x/m[i]<<endl;
		res += (x/m[i]);
	}
	//cout<<"sum at "<<x<<" = "<<res<<endl;
	return res;
}

long long ex(long long x, const vector<long long> &m){
	long long res = 0;
	for (int i = 0; i < m.size(); i++){
		res += (x%m[i] == 0 ? 1 : 0);
	}
	return res;
}


long long solve(long long n, const vector<long long> &m){
	long long ini = -1;
	long long fin = 10000000000000000;

	long long mid;

	while (fin - ini > 1){
		mid = (fin + ini) / 2;

		if (sum(mid, m)+m.size() < n)
			ini = mid;
		else
			fin = mid;

		//cout<<"loop "<<ini<<" "<<fin<<endl;
	}
//	cout<<"exit "<<fin<<endl;
	long long res = 0;
	long long e = sum(fin, m)+m.size() - ex(fin, m);
//	cout<<"real: "<<e<<endl;
	while (e != n){
		if (fin % m[res] == 0)
			e++;
		res++;
	}

	return res;
}

int main(){
	long long t;
	cin>>t;
	for (long long test = 1; test <= t; test++){
		long long b, n;
		cin>>b>>n;
		vector <long long> m(b);
		for (long long i = 0; i < b; i++){
			cin>>m[i];
		}

		printf("Case #%lld: %lld\n", test, solve(n, m));
	}
	return 0;
}
