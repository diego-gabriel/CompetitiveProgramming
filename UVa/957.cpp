#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;


int main()
{
	int nPopes;
	int y;

	while (scanf("%d", &y) == 1)
	{
		scanf("%d", &nPopes);
		int pope, year[nPopes];

		for (int i = 0; i < nPopes; i++)
		{
			scanf("%d", &year[i]);
		}

		int res, iniR, finR;

		res = 0;
		iniR = finR = 0;

		for (int i = 0; i < nPopes; i++)
		{
			int j, n;
			j = i;
			n = 0;

			while (year[j] - year[i] < y)
				n++, j++;
			if (n > res)
			{
				res = n;
				iniR = year[i];
				finR = year[j - 1];
			}
		}

		printf("%d %d %d\n", res, iniR, finR);



	}
	return 0;
}