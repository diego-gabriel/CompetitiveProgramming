#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool orden (int a, int b)
{
	return a > b;
}

int main()
{
	int num;
	
	cin>>num;
	int v[num];
	unsigned long long s = 0;
	unsigned long long res = 0;
	int t = 1;
	for (int i = 0; i < num; i++)
	{
		cin>>v[i];
	}
	
	sort(v, v + num, orden);
	
	for (int i = 0; i < num; i++)
	{
		s += v[i];
		if (i == t-1)
		{
			 res += s;
			 t *= 4;
		 }
	}
	cout<<res<<endl;
	return 0;
}
