#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, k;

	cin>>n>>k;

	bool res = true;
	int tar, v[n];
	k--;
	for (int i  = 0; i < n; i++)
	{
		cin>>v[i];
		if (i == k)
			tar = v[i];
		if (i > k)
			res = res && v[i] == tar;
	}

	if (res)
	{
		while (v[k] == tar && k >= 0)
			k--;
		cout<<k +1 <<endl;
	} else
 	cout<<-1<<endl;

	return 0;
}
