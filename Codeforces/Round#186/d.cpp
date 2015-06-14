#include <iostream>
#include <algorithm>

using namespace std;

struct Comp
{
	int ini;
	int fin;
	int cost;
	
	Comp (){}
	Comp (int a, int b, int c)
	{
		ini = a;
		fin = b;
		cost = c;
	}
}

int main()
{
	int n, m, k;
	
	cin>>n>>m>>k;
	Comp comp[m];
	
	for(int i = 0, i < m; i++)
	{
		cin>>comp[m].ini>>comp[m].fin>>comp[m].cost;
	}
	
	
	
	return 0;
}
