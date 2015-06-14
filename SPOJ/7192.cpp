#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while (cin>>n && n != -1){
		long long x[n], y[n], z[n];

		for (int i = 0; i < n; i++)
			cin>>x[i];
		for (int i = 0; i < n; i++)
			cin>>y[i];
		z[0] = x[1] - x[0];
		z[n-1] = x[n-1] - x[n-2];

		for (int i = 1; i < n-1; i++){
			z[i] = x[i+1] - x[i-1];
		}

		sort(z, z+n);
		sort(y, y+n);

		long long res = 0;

		for(int i = 0; i < n; i++)
			res += (z[i]*y[i]);

		res = res < 0 ? -res : res;

		cout<<res/2;
		if (res % 2)
			cout<<".5"<<endl;
		else cout<<".0"<<endl;

	}
	return 0;
}