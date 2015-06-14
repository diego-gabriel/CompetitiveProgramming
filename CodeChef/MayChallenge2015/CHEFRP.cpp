#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int sum = 0;
		int m = 10000;

		int a;
		for (int i = 0; i < n; i++){
			cin>>a;
			sum += a;

			m = m < a ? m : a;
		}

		if (m > 1){
			cout<<sum - (m-2)<<endl;
		}		else
		cout<<-1<<endl;
	}
}