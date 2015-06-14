#include <iostream>
#include <set>

using namespace std;

set<int> pot;

void init()
{
	for (int i = 5; i <= 3000000; i *= 5)
		pot.insert(i);
}


int main()
{
	int n;
	init();
	while (cin>>n)
	{
		
		if (n%4 == 0)
			cout<<0<<endl;
		else 
			if ((n+1) % 4 == 0 || pot.find(n) != pot.end())
				cout<<2<<endl;
			else 
				cout<<1<<endl;
	}
	return 0;	
}
