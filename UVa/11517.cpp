#include <iostream>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;
	while(nTest--){
		int target;
		cin>>target;
		int n;
		cin>>n;
		int coin[n];
		for (int i = 0; i < n; i++){
			cin>>coin[i];
		}
		int memo[20500];
		for (int i = 0; i < 20500; i++)
			memo[i] = 0x0fffffff;
		memo[0] = 0;
	
		for (int i = 0; i < n; i++){
			for (int p = 20500-1-coin[i]; p >= 0; p--){
				if (memo[p] != 0x0fffffff)
					memo[p+coin[i]] = min(memo[p]+1, memo[p+coin[i]]);
			}
		}
		int r;
		for (r = target; memo[r] >= 0x0fffffff; r++){
	
		}
	
		cout<<r<<" "<<memo[r]<<endl;
	}
}