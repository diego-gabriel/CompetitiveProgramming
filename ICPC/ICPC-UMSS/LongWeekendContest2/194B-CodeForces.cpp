#include <iostream>

using namespace std;

#define ull unsigned long long

ull gcd (ull a, ull b)
{
	return b ? gcd(b, a % b) : a;
}

ull mcm (ull a, ull b)
{
	ull g = gcd(a, b);
	ull n = a/4;
	return (a/g) +1;
}

int main()
{
	int t;
	
	cin>>t;
	
	ull n;
	
	while(t--)
	{
		cin>>n;
		cout<<mcm(4*n, n+1)<<endl;
	}
	return 0;
}
