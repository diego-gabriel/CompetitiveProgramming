#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	bool m[n][n];

	for (int i = 0; i < n; i++)
		cin>>a[i];
	for (int i = 0; i < n ;i++)
		for (int j = 0; j < n; j++){
			char k;
			cin>>k;
			m[i][j] = k == '1';
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				if (m[i][j] && a[j] < a[i]){
					swap(a[i], a[j]);
				}
			}
			for (int j = i-1; j >= 0; j--){
				if (m[i][j] && a[j] > a[i]){
					swap(a[i], a[j]);
				}
			}
		}

	cout<<a[0];
	for (int i = 1; i < n; i++)
		cout<<" "<<a[i];
	cout<<endl;
	return 0;
}