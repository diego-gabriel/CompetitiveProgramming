#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;

	while (nTest--){
		int n;
		cin>>n;
		int lis1[n], lis2[n], seq[n];
		for (int i = 0; i < n; i++){
			lis1[i] = lis2[i] = 1;
		}
		for (int i = 0; i < n; i++)
			cin>>seq[i];
 
 		int res = 0;
		for (int i = n-1; i >= 0; i--){
			for (int j = i; j < n; j++){
				if (seq[i] < seq[j])
					lis1[i] = max(lis1[i], lis1[j]+1);
				if (seq[i] > seq[j])
					lis2[i] = max(lis2[i], lis2[j]+1);
			}	
			res = max(res, lis1[i] + lis2[i]-1);
		}
		cout<<res<<endl;
	}
	return 0;
}