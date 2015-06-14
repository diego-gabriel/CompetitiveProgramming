#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){

	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		int d;
		int v;
		vector <int> pankakes;
		int mi = 0;

		cin>>d;
		for (int i = 0; i < d; i++){
			cin>>v;
			pankakes.push_back(v);
		}

		int best = 1000;

		for (int i = 1000; i > 0; i--){
			int nOfCuts = 0;
			for (int j = 0; j < pankakes.size(); j++){
				int pank = pankakes[j];
				nOfCuts += ((pank + i-1) / i)-1;
			}
			best = best > nOfCuts + i ? nOfCuts + i : best;
		}

		printf("Case #%d: %d\n", test, best);
	}

	return 0;
}