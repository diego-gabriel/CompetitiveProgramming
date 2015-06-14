#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

unsigned long long MOD = 1000000007;
bool isPrime[100000+5];
int nOfPrimes;
int prime[10000];

int n_OfPrimes(){
	int res = 0;
	for (int i = 0; i < 100000+5; i++){
		if (isPrime[i]){
			prime[res] = i;
			res++;
		}
	}
	return res;
}

void initCrib(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 1000; i++){
		if (isPrime[i])
			for (int j = i*2; j < 100000+5; j += i)
				isPrime[j] = false;
	}
	nOfPrimes = n_OfPrimes();
}

inline int max(int a, int b){
	return a > b ? a : b;
}

inline vector <int> factorize(int n){
	vector <int> res;
	for (int i = 0; i < nOfPrimes && n > 1; i++){
		int f = 0;
		while (n % prime[i] == 0){
			f++;
			n /= prime[i];
		}
		res.push_back(f);
	}
	return res;
}

inline void mcm(vector <int> &a, vector <int> b){
	for (int i = 0; i < b.size(); i++){
		a[i] = max(a[i], b[i]);
	}
}

unsigned long long pow(unsigned long long b, unsigned long long e){
	return e == 0 ? 1 : (((pow(b, e/2) * pow(b, e/2)) % MOD) * (e % 2 == 1 ? b : 1)) % MOD;
}

inline unsigned long long multiply(vector<int> &vec){
	unsigned long long res = 1;
	for (int i = 0; i < nOfPrimes; i++){
		res = res * pow(prime[i], vec[i]);
		res %= MOD;
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	initCrib();
	while (t--){
		int n;
		cin>>n;
		int pos[n];
		bool vis[n];
		for (int i = 0; i < n; i++){
			cin>>pos[i];
			pos[i]--;
			vis[i] = false;
		}

		vector <int> res(nOfPrimes, 0);
		for (int i = 0; i < n; i++){
			if (!vis[i]){
				int k = i;
				int lon = 0;
				while (!vis[k]){
				 	vis[k] = true;
					k = pos[k];
					lon++;
				}
				mcm(res, factorize(lon));
			}
		}

		cout<<multiply(res)<<endl;

	}
	return 0;
}