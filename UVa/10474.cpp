#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n, q;
	int test = 0;
	while ((scanf("%d %d", &n, &q)) == 2 && (n || q))
	{
		test++;

		vector <int> vec;
		int v;
		while (n--)
		{
			scanf("%d", &v);
			vec.push_back(v);
		}
		map <int, int> r;
		sort(vec.begin(), vec.end());

		for (int i = 0; i < vec.size(); i++)
		{
			if (r[vec[i]] == 0) r[vec[i]] = i+1;
		}

		printf("CASE# %d:\n", test);
		int res;
		while(q--)
		{
			scanf("%d", &v);
			res = r[v];
			if (res) printf("%d found at %d\n", v, res);
			else printf("%d not found\n", v);
		}
	}

	return 0;
}