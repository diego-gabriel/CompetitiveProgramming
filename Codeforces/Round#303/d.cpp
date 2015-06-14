#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int p[n];
	for (int i = 0; i <n; i++){
		cin>>p[i];
	}
	sort(p, p+n);

	int dis = 0;
	int tot = 0;

	for (int i = 0; i <n ; i++){
		if (tot > p[i])
			dis++;
		else
			tot += p[i];
	}

	cout<<n-dis<<endl;
	return 0;
}