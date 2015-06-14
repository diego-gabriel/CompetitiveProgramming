#include <iostream>

using namespace std;

int tam (int n)
{
	return n == 0 ? 0 : 1 + tam(n/10);
}

int num(int i, int n)
{
	return i == 0 ? n % 10 : num(i-1, n/10);
}

int solve(int v, int n)
{
	int t = tam(n);
	return v <= t ? num(t - v, n) : solve (v - t, n+1);
}

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		long long  v;
		cin>>v;
		
		long long r = 1;
		long long s = 1;
		while (v > r)
		{
			v -= r;
			s++;
			r += tam(s);
		}	

		cout<<solve(v, 1)<<endl;
	}
	return 0;
}