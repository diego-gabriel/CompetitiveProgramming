#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, t;
	cin>>n>>t;
	int a[n+2];
	bool vis[n+2];
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < n-1; i++)
		cin>>a[i+1];

	int current = 1;

	while (current != t && current < n && !vis[current]){
		vis[current] = true;
		current = current + a[current];
	}

	if (current == t)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}