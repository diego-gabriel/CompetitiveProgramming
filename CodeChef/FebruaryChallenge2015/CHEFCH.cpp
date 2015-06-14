#include <iostream>
#include <cstdio>
#include <iostream>

using namespace std;

char s[2];

int min(int a, int b){
	return a < b ? a : b;
}

int solve(string cad, int k){
	int res = 0;

	for (int i = 0; i < cad.length(); i++){
		if (cad[i] != s[k])
			res++;
		k = 1-k;
	}

	return res;
}

int main(){
	int n;
	cin>>n;
	s[0] = '-';
	s[1] = '+';
	while (n--){
		string cad;
		cin>>cad;
		cout<<min(solve(cad, 1), solve(cad, 0))<<endl;
	}
	return 0;
}