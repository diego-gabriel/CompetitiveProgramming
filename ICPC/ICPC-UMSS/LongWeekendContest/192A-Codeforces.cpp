#include <iostream>
#include <set>

using namespace std;

int main()
{
	set <int> sum;
	int last = 0;
	
	int n;
	
	cin>>n;
	
	for (int i = 1; last < n; last += i, i++)
	{
		sum.insert(last);
	}
	bool ok = false;
	set <int> :: iterator it;
	it = sum.begin();
	
	do
	{
		ok = sum.find(n - *it) != sum.end();
		it++;
	} while (!ok && it != sum.end());
	
	cout<<(ok ? "YES" : "NO")<<endl;
	
	return 0;
}
