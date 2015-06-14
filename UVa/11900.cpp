#include <iostream>

using namespace std;

int main()
{
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++)
	{
		int res = 0;
		int n, p, q;

		cin>>n>>p>>q;

		int e;

		for (int i = 0; i < n; i++)
		{
			cin>>e;
			if (p && q >= e)
			{
				q -= e;
				p--;
				res++;
			}
		}

		cout<<"Case "<<test<<": "<<res<<endl;
	}
	return 0;
}