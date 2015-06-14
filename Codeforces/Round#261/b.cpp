#include <iostream>

using namespace std;

int main(){
	long long n;
	long long max, min, nmax, nmin;
	max = 0;
	min = 1000000003;
	nmax = 0;
	nmin = 0;
	long long b;
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>b;
		if (b < min){
			min = b;
			nmin = 0;
		}

		if (b == min)
			nmin++;
		if (b > max){
			max = b;
			nmax = 0;
		}
		if (b == max)
			nmax++;
	}

	cout<<max-min<<" "<<((nmax == nmin && nmin == n)? (n*(n-1))/2 : nmax*nmin)<<endl;

	return 0;
}