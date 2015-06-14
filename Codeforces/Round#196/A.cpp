#include <iostream>
#include <algorithm>

using namespace std;

bool ord(int a, int b)
{
	return a < b;
}

int main()
{
	int n, m;
	cin>>n>>m;
	int puz[m];
	for (int i = 0; i < m; i++)
		cin>>puz[i];
	sort(puz, puz+m, ord);
	int res = 0x7fffffff;
	for (int i = n-1; i < m; i++)
	{
		res = min(res, puz[i] - puz[i - n + 1]);
	}
	cout<<res<<endl;
	return 0;
}