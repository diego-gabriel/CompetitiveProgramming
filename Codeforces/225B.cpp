#include <iostream>

using namespace std;

int kBonacci(int k, int n)
{
	int res = 0;
	if (k == n) res = 1;
	else
		if (k < n)
		for (int i = 1; i <= k; i++)
		{
			res += kBonacci(k, n - i);
		}
	cout<<"kbonacci("<<k<<", "<<n<<") = "<<res<<endl;
	return res;
}

int main()
{
	int n, k;

	cin>>k>>n;

	cout<<kBonacci(k, n)<<endl;

	return 0;
}