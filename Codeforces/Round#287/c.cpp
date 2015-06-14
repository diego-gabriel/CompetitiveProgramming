#include <iostream>

using namespace std;


const long long uno = 1;
long long prec[60];

char otherDir(char d){
	return d == 'L' ? 'R' : 'L';
}

long long solve(long long h, long long n, char d, long long left, long long right){
	long long res = 0;
	if (h == 0)
		res = 0;
	else{
		long long mid = (left + right) / 2;
		char dirOfN = n <= mid ? 'L' : 'R';

		if (n <= mid){
			right = mid;
		}
		else{
			left = mid + 1;
		}

		long long plus = 0;
		if (dirOfN != d){
			plus = prec[h-1];
			d = dirOfN;
		}
		res = 1 + solve(h-1, n, otherDir(d), left, right) + plus;
	}
	return res;
}

void init(){
	long long p = uno;
	prec[0] = 1;
	p = p << 1;
	for (int i = 1; i < 60; i++){
		prec[i] = prec[i-1] + p;
		p = p << 1;
	}
}

int main(){
	init();
	long long h, n;
	cin>>h>>n;
	cout<<solve(h, n, 'L', 1, uno << h)<<endl;
	return 0;
}