#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	if (a == b) return a;
	if (a > b) return gcd(a - b, b);
	return gcd(a, b - a);
}

int main()
{
	double a, b, c, d;

	cin>>a>>b>>c>>d;

	long long A, B, C, D;

	A = a;
	B = b;
	C = c;
	D = d;
	if (a/b < c/d)
	{
		long long g = gcd(B*C - A*D, B*C);
		cout<<(B*C - A*D)/g<<"/"<<(B*C) / g<<endl;
	}		else
	if (a/b > c/d)
	{
		long long g = gcd(A*D - B*C, A*D);
		cout<<(A*D - B*C)/g<<"/"<<(A*D) / g<<endl;
	}
	else cout<<"0/1"<<endl;
	return 0;
}