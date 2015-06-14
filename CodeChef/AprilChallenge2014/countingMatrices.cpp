#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 1250*1250
int memo[MAX];

void init(){
	memset(memo, 0, sizeof(memo));

	for (int i = 1; i < MAX; i++)
	{
		int k = 1;
		while (k * i < MAX){
			memo[k*i]++;
			k++;
		}
	}

	for (int i = 1; i < MAX; i++){
		memo[i] += memo[i-1];
	}
}

long long solve(int n){

	int k = n-1;
	long long res = 0;
	for (int i = 1; k > 0; i++, k--){
		res += memo[i*k-1];
	}

	return res;
}

int main()
{
	int test;

	cin>>test;
	init();
	while(test--){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}