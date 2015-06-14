#include <iostream>

using namespace std;

unsigned long long c[64];
unsigned long long p[64];

void init(){
	c[0] = 1;
	p[0] = 1;
	for (int i = 1; i < 64; i++){
		c[i] = 2*c[i-1] + p[i-1] -1;
		p[i] = p[i-1]*2;
	}
}

unsigned long long solve(unsigned long long n){
	unsigned long long tot = 0;
	unsigned long long UNO = 1;
	int b = 0;;
	for (int i = 63; i >= 0; i--){
		if (n & (UNO<<i)){
			tot = tot + c[i] + p[i]*b;
			b++;
		}
	}
	return tot;
}

int main(){
	init();
	unsigned long long a, b;
	while(cin>>a>>b)
		cout<<solve(b) - solve(a-1)<<endl;
	return 0;
}