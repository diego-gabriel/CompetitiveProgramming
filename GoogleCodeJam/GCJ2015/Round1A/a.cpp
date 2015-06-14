#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int solve1(const vector <int> &v){
	int res = 0;

	for (int i = 1; i < v.size(); i++){
		res += (v[i-1]-v[i] > 0 ? v[i-1]-v[i] : 0);
	}

	return res;
}


int max_branch(const vector <int> &v){
	int res = 0;


	for (int i = 1; i < v.size(); i++){
		int dif = v[i-1]-v[i];
		res = res > dif ? res : dif;

	}
	return res;
}

int solve2(const vector <int> &v){
	int res = 0;
	int rate = max_branch(v);
	for (int i = 0; i < v.size()-1; i++){
		res += min(rate, v[i]);
	}

	return res;
}


int main(){
	int t;
	cin>>t;
	for(int test = 1; test <= t; test++){
		int n;
		cin>>n;
		vector <int> v(n);
		for (int i = 0; i < n; i++){
			cin>>v[i];
		}
		printf("Case #%d: %d %d\n", test, solve1(v), solve2(v));
	}
	return 0;
}