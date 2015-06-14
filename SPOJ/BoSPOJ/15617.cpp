#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	map <int, int> m;
	map <int, int> :: iterator it;

	unsigned long long pot = 2;

	for (int i = 1; i <= 64; i++)
	{
		m[pot-1] = i;
		pot *= 2;
	}

	m[1] = 1;
	int n;



	while (cin>>n)
	{
		for (it = m.begin(); it != m.end() && n > it->first; it++)
		{

		}

		

		cout<<it->second<<endl;

	}

	return 0;
}
