#include <iostream>

using namespace std;

int fact[50];

int pow( int a, int b)
{
	return b ? (a*pow(a, b-1)) % 1007 : 1;
}
/*
int pow(int b, int e)
{
	int res = 1;
	
	while (e)
	{
		if (e % 2)
			res = (res * b) % 1007;
		b = (b*b) % 1007;
		e /= 2;
	}
	
	return res;
}
*/
int inv(int x)
{
	for (int i = 1;i < 1007; i++)
		if (x*i % 1007 == 1) return i;
}

int comb(int k, int n)
{
	int res;
	int num, den;
	den = (fact[k]*fact[n-k]) % 1007;
	num = fact[n];
	
	res = (num*inv(den)) % 1007;
	cout<<"com: "<<res<<" "<<num<<" "<<den<<" "<<inv(den)<<endl;
	return res;
}

int f(int n, int m, int i)
{
	int res = 1;
	
	res = (fact[i] * (comb(n-i, n) * comb(m-i, m)) % 1007) % 1007;
	cout<<"res: "<<res<<endl;
	return res;
}

int main()
{
	
	cout<<inv(15)<<endl;
	int nTest;
	
	cin>>nTest;
	
	fact[0] = 1;
	for (int i = 1; i < 50; i++)
	{
		fact[i] = (fact[i-1]*i) % 1007;
	}
	
	while (nTest--)
	{
		int n, m;
		cin>>n>>m;
		
		if (n > m) 	swap(n, m);
		int res = 0;
		
		for (int i = 0; i <= n; i++)
		{
			res += f(n, m, i);
			res %= 1007;
		}
		
		cout<<res<<endl;
		
	}
	
	return 0;
}
