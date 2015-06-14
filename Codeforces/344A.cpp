#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int res = 1;
	string m, last;
	n--;
	cin>>last;
	while (n--)
	{
		cin>>m;
		if (last != m) res++;
		last = m;
	}
	cout<<res<<endl;
	return 0;
}
