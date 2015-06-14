#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long a[4];
	long long b[4];
	a[0] = a[1] = a[2] = a[3] = 9999;
	bool ok = true;
	for (int i = 0; i < n; i++)
		cin>>a[i];

	sort(a, a+4);
	if (n == 0){
		a[0] = a[1] = 1;
		a[2] = a[3] = 3;
		for (int i = 0; i < 4; i++)
			b[i] = a[i];
	}
	else
	if (n == 4){	
	}
	if (n == 1){
		a[1] = a[0];
		a[2] = 4*a[0] - a[1];
		a[3] = 3*a[0];	
		for (int i = n; i < 4; i++)
			b[i] = a[i];

	}
	else
	if (n == 2){
		a[2] = 4*a[0] - a[1];
		a[3] = 3*a[0];
		for (int i = n; i < 4; i++)
			b[i] = a[i];	
	}
	else
	if (n == 3){
		a[3] = 3*a[0];
		for (int i = n; i < 4; i++)
			b[i] = a[i];
	}
	sort(a, a+4);
		long long sum = a[0];
		for (int i = 1; i < 4; i++){
			ok = ok && a[i] >= a[i-1];
			sum += a[i];
		}
		ok = ok && (sum == 2*(a[1]+a[2]) && sum == 4*(a[3]-a[0]));
		if (ok){
			cout<<"YES"<<endl;
			for(int i = n; i < 4; i++)
				cout<<b[i]<<endl;
		}
		else
			cout<<"NO"<<endl;	
	return 0;
}
