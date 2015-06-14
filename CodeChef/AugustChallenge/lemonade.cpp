#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool orden (int a, int b)
{
	return a > b;
}

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		int n, m;
		cin>>n>>m;

		vector <int> visited;
		int room;

		for (int i = 0; i < m; i++)
		{
			cin>>room;
			visited.push_back(room);
		}

		vector <int> rooms[n];
		int nBottle, bottle;

		for (int i = 0; i < n; i++)
		{
			cin>>nBottle;

			for (int k = 0; k < nBottle; k++)
			{
				cin>>bottle;
				rooms[i].push_back(bottle);
			}

			sort(rooms[i].begin(), rooms[i].end(), orden);
		}

		int res = 0;

		for (int i = 0; i < m; i++)
		{
			room = visited[i];

			if (!rooms[room].empty())
			{
				res += rooms[room][0];
				rooms[room].erase(rooms[room].begin());
			}
		}

		cout<<res<<endl;
	}

	return 0;
}