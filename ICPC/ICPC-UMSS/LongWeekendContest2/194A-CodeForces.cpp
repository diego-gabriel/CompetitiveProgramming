#include <iostream>

using namespace std;

int main()
{
	int n, k;
	
	cin>>n>>k;
	
	int res = 0;
	
	while (n*3 > (k - 2*res))
	{
		res++;
		n--;
	}
	
	cout<<res;
	
	return 0;
}

