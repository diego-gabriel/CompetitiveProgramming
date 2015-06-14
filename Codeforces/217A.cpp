#include <iostream>
#include <set>
#include <map>
#include <cstring>

using namespace std;

set <int> hor[1001], ver[1001];
map <pair<int, int>, bool> vis;
map <pair<int, int>, bool> :: iterator it;

void dfs(int x, int y)
{
	vis[make_pair(x, y)] = false;
	set <int> :: iterator ix, iy, tx, ty;

	ix = tx = hor[y].find(x);
	iy = ty = ver[x].find(y);

	tx++;

	if (tx != hor[y].end() && vis[make_pair(*tx, y)])
	{
		dfs(*tx, y);
	}

	tx = ix;
	
	if (tx != hor[y].begin() && vis[make_pair(*(--tx), y)])
	{
		dfs(*tx, y);
	}

	ty++;

	if (ty != ver[x].end() && vis[make_pair(x, *ty)])
	{
		dfs(x, *ty);
	}

	ty = iy;
	
	if (ty != hor[y].begin() && vis[make_pair(x, *(--ty))])
	{
		dfs(x, *ty);
	}


}

int main()
{
	int n;
	int x, y;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>x>>y;
		hor[y].insert(x);
		ver[x].insert(y);
		vis[make_pair(x, y)] = true;
	}


	int nGroups = 0;
	for (it = vis.begin(); it != vis.end(); it++)
	{
		if (it -> second)
		{
			nGroups++;
			pair <int, int> p = it -> first;
			dfs(p.first, p.second);
		}
	}

	cout<<nGroups-1<<endl;

	return 0;
}