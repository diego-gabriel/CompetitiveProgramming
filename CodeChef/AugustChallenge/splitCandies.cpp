#include <iostream>

using namespace std;

int main()
{
	long long n, k, t;

	cin>>t;

	while(t--)
	{
		cin>>n>>k;
		if (k == 0) cout<<"0 "<<n<<endl;
		else
		cout<<n/k<<" "<<n%k<<endl;
	}
	return 0;
}