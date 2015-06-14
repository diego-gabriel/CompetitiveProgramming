#include <iostream>
#include <map>

using namespace std;

int isOk(int i)
{
	int res = 1;
	map <int, int> dig;
	while (i && res)
	{
		dig[i % 10]++;

		if (dig[i % 10] > 1){
			res = 0;
		}

		i /= 10;
	}

	return res;
}

int main()
{
	int tot[50000 + 1];
	tot[0] = 0;

	for (int i = 1; i < 50001; i++)
	{
		tot[i] = tot[i-1] + isOk(i);
	}

	int n, m;

	while (cin>>n>>m)
	{
		cout<<tot[m] - tot[n-1]<<endl;
	}

	return 0;
}