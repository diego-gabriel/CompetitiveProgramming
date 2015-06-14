#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while (t--){
		int n;
		cin>>n;
		int a[n];

		for (int i = 0; i < n; i++)
			cin>>a[i];

		int res = 0;

		for (int i = 0; i < n; i++){
			bool ok = true;
			if (i > 0)
				ok = a[i] == a[i-1];
			if (i < n-1)
				ok = ok && a[i] == a[i+1];

			if (!ok)
				res++;
		}

		cout<<res<<endl;
	}
}