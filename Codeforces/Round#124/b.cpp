#include <iostream>

using namespace std;

#define INF 0x0fffffff

int abs(int a){
	return a > 0 ? a : -a;
}

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){
	int n, m;
	cin>>n>>m;
	int a[n+1];
	int b[m+1];

	for(int i = 0; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 0; i <= m; i++){
		cin>>b[i];
	}

	if (n > m){
		if (a[0]*b[0] < 0)
			cout<<'-';
		cout<<"Infinity"<<endl;
	} else if (n < m){
		cout<<"0/1"<<endl;
	} else {
		if (b[0] < 0){
			b[0] *= -1;
			a[0] *= -1;
		}
		
		int g = gcd(abs(a[0]), abs(b[0]));
		
		cout<<a[0]/g<<"/"<<b[0]/g<<endl;
	}	


	return 0;
}