#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){

	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		int m;
		string cad;
		cin>>m>>cad;
		int stand = 0;
		int inv = 0;
		for (int i = 0; i < m+1; i++){
			int d = max(0, i - stand); 
			inv += d;
			stand += d;
			stand += (cad[i]-'0');
		}

		printf("Case #%d: %d\n", test, inv);
	}
	return 0;
}