#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>


using namespace std;

set<char> keys;
double cant;
double bananas;
double maxBananas;
string target;

string sub(string cad, int i, int n){
	string res = "";

	while(i < n){
		res = res + cad[i];
		i++;
	}

	return res;
}

double count(string cad){
	int n = target.size();
	double res = 0.0;
	for (int i = 0; i < cad.size()-n; i++){
		if (target == sub(cad, i, i+n))
			res += 1.0;
	}
	return res;
}

void solve(string cad, int s){
	if (s == 0){
		double b = count(cad);
		maxBananas = max(maxBananas, b);
		cant += 1.0;
		bananas += b;
	}
	else
	{
		set<char> :: iterator it;
		for (it = keys.begin(); it != keys.end(); it++){
			solve(cad + *it, s-1);
		}
	}
}

int main(){

	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int k, l, s;
		cin>>k>>l>>s;
		keys.clear();
		cant = bananas = maxBananas = 0.0;
		for (int i = 0; i < k; i++){
			char car;
			cin>>car;
			keys.insert(car);
		}
		cin>>target;

		solve("", s);

		printf("Case #%d: %.6lf\n", test, maxBananas-(bananas/cant));
	}

	return 0;
}