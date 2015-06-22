#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while (t--){
		int n, k;
		cin>>n>>k;
		int v;
		int sum= 0;
		while(n--){
			cin>>v;
			if (v%2 == 1)
				sum = 1-sum;
		}

		if (k > 1){
			sum = 0;
		} else
			sum = 1-sum;

		if (sum == 1){
			cout<<"odd"<<endl;
		}
		else
			cout<<"even"<<endl;
	}
	return 0;
}