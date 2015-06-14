#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	long long p, d;

	cin>>p>>d;
	vector <long long> pos;

	p++;

	long long mod = 1;
	bool ok = (d-1) >= (p%mod);
	while (d - (p%mod) >= 0)
	{
		d -= (p%mod);
		p -= (p%mod);
		mod *= 10;
	}

	cout<<p-1<<endl;
	//cout<<(ok ? p-1 : p)<<endl;

}