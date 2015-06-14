#include <iostream>

using namespace std;

int main(){
	int test;
	cin>>test;

	while (test--){
		int n;
		int max, min;
		max = 0;
		min = 100;
		cin>>n;
		int v;
		for (int i = 0; i < n; i++){
			cin>>v;
			min = min < v ? min : v;
			max = max < v ? v : max;
		}
		cout<<(max-min)*2<<endl;
	}
	return 0;
}