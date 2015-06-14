#include <iostream>

using namespace std;

int l (int n)
{
	return n / 10;
}

int bl (int n)
{
	return (n/100) * 10 + n%10;
}

int main()
{
	int n;
	
	cin>>n;
	
	if (n >= 0) cout<<n;
	else cout<<- min(l(-n), bl(-n));
	
	return 0;
}
