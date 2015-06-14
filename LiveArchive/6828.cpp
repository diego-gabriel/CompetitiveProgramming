#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}
int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	int n;
	while (cin>>n){
		vector <int> v(n);
		for(int i = 0; i < n; i++)
			cin>>v[i];

		sort(v.begin(), v.end());

		v.push_back(v[0]);
		int t1 = 0;
		int t2 = 0;
		//0 1 2 3 4
		for (int i = 0; i < v.size()-1; i += 2){
			t1 += min(abs(v[i] - v[i+1]), 24 - abs(v[i] - v[i+1]));
		}
		for (int i = 1; i < v.size(); i += 2){
			t2 += min(abs(v[i] - v[i+1]), 24 - abs(v[i] - v[i+1]));
		}

		cout<<min(t1, t2)<<endl;
	}
	return 0;
}