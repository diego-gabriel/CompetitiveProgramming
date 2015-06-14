#include <iostream>

using namespace std;

int solve(int candles, int out, int rest)
{
	return candles == 0 ? 0 : candles + solve((candles + rest)/ out, out,(candles + rest) % out);
}

int main()
{
	int n, m;

	cin>>n>>m;

	cout<<solve(n, m, 0)<<endl;
	return 0;
}