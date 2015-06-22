#include <iostream>
#include <algorithm>

using namespace std;



int main(){
	int n;
	cin>>n;

	int a[n];
	int sum = 0;

	for (int i =0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}

	int taked = 0;
	int s = 0;

	sort(a, a+n);

	n--;
	while(n >= 0 && 2*s <= sum){
		taked++;
		s += a[n];
		n--;
	}

	cout<<taked<<endl;
	return 0;
}