#include <iostream>

using namespace std;

int main()
{
	int n, m, k, t;
	
	cin>>t;
	
	while (t--)
	{
		cin>>n>>m>>k;
		int res = k;
		
		if (n > 1 && m > 1)
		{
			res = (k+1) / 2;
		}
		else
		if ((n == 1 && m > 2) || (n > 2 && m == 1))
		{
			res = k;
		} else res = 0;
		
		cout<<res<<endl;
	}
	
	return 0;
}
