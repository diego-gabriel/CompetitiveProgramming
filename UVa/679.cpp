#include <iostream>

using namespace std;

int solve (int ball, int niv, int one, int res)
{
	if (niv)
	{
		int bit = ball & 0x00000001;
		res = solve(ball>>1, niv-1, one && bit == 0, (res<<1) | (one ? (bit == 0 ? 1 : 0) : bit));
	}
	return res;
}

int main()
{
	int n;
	
	int d, b;
	cin>>n;
	while (n--)
	{
		cin>>d>>b;
		cout<<solve(b, d-1, true, 1)<<endl;
	}
	return 0;
}
