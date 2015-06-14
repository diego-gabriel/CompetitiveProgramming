#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	map <int, bool> mark;

	int a[n], l;
	int res[n+1];

	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	res[n-1] = 1;
	mark[a[n-1]] = true;

	for (int i = n-2; i >= 0; i--)
	{
		res[i] = res[i+1] + (mark[a[i]] ? 0 : 1);
		mark[a[i]] = true;
		//cout<<"res; "<<res[i]<<endl;
	}

	
	for (int i = 0; i < m; i++)
	{
		cin>>l;
		cout<<res[l-1]<<endl;
	}
	return 0;
}