#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10005

int main(){


	bool memo[MAX];
	memset(memo, true, sizeof(memo));
	memo[0] = memo[1] = false;

	for(int i = 2; i*i < MAX; i++){
		if (memo[i])
			for(int k = i+i; k < MAX; k += i){
				memo[k] = false;
			}
	}

	int v;

	int f[MAX];
	memset(f, 0, sizeof(f));

	for(int i = 0; i < 10; i++){
		cin>>v;
		int d = 2;
		while(v != 1){
			if (v % d == 0){
				f[d]++;
				v /= d;
			} else {
				do{
					d++;
				} while(!memo[d]);
			}
		}
	}

	int n = 1;

	for(int i = 0; i < MAX; i++){
		n = n +(n*f[i]);
		n %= 10;
	}

	cout<<n<<endl;
	return 0;
}