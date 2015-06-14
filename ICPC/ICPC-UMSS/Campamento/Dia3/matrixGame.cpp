#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
	int x, y;

	while (cin>>x>>y && x > 0 && y > 0)
	{
		vector <bool> mat[x];
		vector <bool> des[x];
		bool a;

		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				cin>>a;
				mat[i].push_back(a);
			}
		}
		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				cin>>a;
				des[i].push_back(a);
			}
		}

		sort(mat.begin(), mat.end(), orderMat);
		sort(des.begin(), des.end(), orderMat);


	}

	return 0;
}