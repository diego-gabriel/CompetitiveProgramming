#include <iostream>

using namespace std;

long long sum(long long n){
	long long res;
	res = ((n+1)*n)/2;
	return res;
}

int main(){
	int n;
	cin>>n;
	while (n--){
		long long n, m;
		cin>>n>>m;
		cout<<sum(m-1) - sum(m-n-1)<<endl;
	}
	return 0;
}