#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	int res[n+1];
	for(int i = 1; i<= n; i++)
		cin>>a[i];

	for(int i = 1; i <= n; i++){
		int higher = 0;
		for(int j = 1; j <= n; j++){
			if (a[j] > a[i])
				higher++;
		}
		res[i] = 1+higher;
	}

	cout<<res[1];
	for(int i = 2; i <= n; i++){
		cout<<" "<<res[i];
	}
	cout<<endl;

	return 0;
}