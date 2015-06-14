#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int s[n];
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	
	multiset <int> a;
	int ab[n*n];
	int ef[n*n];
	int res = 0;
	
	for (int i = 0; i < n; i++)
		for (int c = 0; c < n; c++)
			ab[n*i + c] = s[i] * s[c], ef[n*i + c] = s[i] + s[c];
			
	for (int i = 0; i < n; i++)
		for (int c = 0; c < n*n; c++)
			a.insert(s[i] + ab[c]);
	
	cout<<"ok"<<endl;
	
	for (int i = 0; i < n; i++)
		for (int c = 0; c < n*n; c++)
		{
			res += a.count(s[i] * ef[c]);
		}
			
	printf("%d\n", res);
	
	
	return 0;
}
