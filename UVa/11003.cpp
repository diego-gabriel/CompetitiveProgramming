#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

struct Box
{
	int weigth;
	int maxLoad;

	Box(){};

	void leer()
	{
		cin>>weigth>>maxLoad;
	}
};

int main()
{
	int n;

	while (cin>>n && n)
	{
		Box box[n + 1];
		
		int knapsack[6001];
		int res = 0;

		for (int i = 0; i < n; i++)
		{
			box[i].leer();		
		}

		memset(knapsack, 0, sizeof(knapsack));

		for (int i = n-1; i >= 0; i--)
		{
			for (int w = box[i].weigth + box[i].maxLoad; w >= box[i].weigth; w--)
			{
				if (w > 6000) continue;

				knapsack[w] = max(knapsack[w], knapsack[w-box[i].weigth] + 1);
				res = max(knapsack[w], res);
			}
		}

		cout<<res<<endl;

	}

	return 0;
}