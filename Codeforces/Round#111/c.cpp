#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long n, k;
	cin>>n>>k;

	long long a[n];
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	k--;
	sort(a, a + n);
	long long  x = k/n;
	long long y = k%n;

	cout<<a[x]<<" ";

	int cons = 0;
	while(x > 0 && a[x-1] == a[x]){
		cons++;
		x--;
	}

	int cant = 1;

	while (x < n && a[x+1] == a[x]){
		cant++;
		x++;
	}

	cout<<a[(cons*n + y)/cant]<<endl;

	return 0;
}