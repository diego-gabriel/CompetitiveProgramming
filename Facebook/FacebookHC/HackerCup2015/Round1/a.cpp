#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

using namespace std;

#define MAX 10000005

bool prime[MAX];
int primacity[MAX];

void criba(){
	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(MAX); i++){
		if (prime[i])
			for (int k = 2*i; k < MAX; k += i)
				prime[k] = false;
	}
}

void init(){
	criba();

	memset(primacity, 0, sizeof(primacity));

	for (int i = 2;i < MAX ; i++){
		if (prime[i]){
			for (int k = i; k < MAX; k += i)
				primacity[k]++;
		}
	}


}

int main(){

	init();
	
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int a, b, k;
		cin>>a>>b>>k;
		int res = 0;
		for (int i = a; i <= b; i++){
			if (primacity[i] == k)
				res++;
		}

		cout<<"Case #"<<test<<": "<<res<<endl;
	}
	//*/
	return 0;
}