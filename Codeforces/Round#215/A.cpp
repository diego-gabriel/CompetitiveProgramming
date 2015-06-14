#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, d;

	cin>>n>>d;

	int price[n];

	for (int i = 0; i < n; i++)
		cin>>price[i];

	sort(price, price + n);

	int res = 0;
	int m;

	cin>>m;
	int i = 0;

	for (i = 0; i < min(m, n); i++)
	{
		res += price[i];
	}

	res -= d*max(0, m-n);

	cout<<res<<endl;

	return 0;
}