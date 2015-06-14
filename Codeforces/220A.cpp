#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool orden(int a, int b)
{
	return a < b;
}

int main()
{
	int n;
	cin>>n;

	int val[n];
	int ord[n];

	for (int i = 0; i < n; i++)
	{
		cin>>val[i];
		ord[i] = val[i];
	}

	sort(ord, ord + n, orden);

	int c = 0;

	for (int i = 0; i < n; i++)
	{
		c += ord[i] != val[i];
	}

	if (c <= 2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}