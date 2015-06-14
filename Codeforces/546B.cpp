#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int v[n];
	for (int i = 0; i < n; i++){
		cin>>v[i];
	}
	sort(v, v+n);

	int res = 0;
	int last = -1;
	for (int i = 0; i < n; i++){
		if (last >= v[i]){
			res += (last-v[i]+1);
			last++;
		}
		else 
			last = v[i];
	}
	cout<<res<<endl;
	return 0;
}