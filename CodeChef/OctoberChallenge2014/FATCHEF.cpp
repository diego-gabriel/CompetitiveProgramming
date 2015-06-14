#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MOD 1000000009

int main(){
	int t;
	scanf("%d\n", &t);
	int n, m;
	while (t--){
		scanf("%d %d\n", &n, &m);
		char f[n];
		memset(f, '-', sizeof(f));
		//cout<<"setted"<<endl;
		int p;
		char k;
		for (int i = 0; i < m; i++){
			
			scanf("%c %d\n", &k, &p);
			f[p-1] = k;
		}
		long long res = 1;
		char ccol;
		long long lp;
		long long i = 0;
		while (f[i] == '-') i++;
		ccol = f[i];
		lp = i;
		i++;

		while (i < n){
			//cout<<i<<endl;
			if (f[i] != '-'){
				if (ccol != f[i]){
					res = res * (i - lp);
					res = res % MOD;
				}

				ccol = f[i];
				lp = i;
			}

			i++;
		}
		cout<<res<<endl;

	}
}