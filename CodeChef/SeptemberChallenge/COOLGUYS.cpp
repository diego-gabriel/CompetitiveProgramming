#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long n;
		cin>>n;

		long long d = 1;
		long long res = 0;
		long long mid = n/2;
		if (n == 1)
			res = 1;
		else 
		if (n == 3) res = 5;
			
		else
		{
			while (n/d != 2)
			{
				res += n/d;
				d++;
			}
	
			res += 2*(mid - d + 1);
			res += (n - mid);

		}

		long long den = n*n;

		long long g = gcd(res, den);
		cout<<res / g<<"/"<<den/g<<endl;
	}

}