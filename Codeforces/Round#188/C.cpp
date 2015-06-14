#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>

using namespace std;


int main()
{
	long long x, y, m;
	
	cin>>x>>y>>m;
	
		long long dif;
		long long res = 0;
		if (x > y)
			swap(x, y);
		
		dif = m - x;
		
		if (m < 0)
		{
			if (x < m && y < m)
			{
				cout<<-1;
				return 0;
			}
		}
		if (m > 0)
		{
			if (x <= 0 && y <= 0)
			{
				cout<<-1;
				return 0;
			}
		}
		if (m==0)
		{
			if ((x < 0 && y < 0))
			{
				cout<<-1;
				return 0;
			}
			
		}

		
		while (y < m)
		{
			x = x+y;
			if (x > y)
				swap(x, y);
			res++;
		}
		cout<<res;

	return 0;
}
