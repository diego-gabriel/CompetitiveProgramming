#include <iostream>

using namespace std;
int pa[3000];

int abs(int a)
{
	return a > 0 ? a : -a;
}

int getDif()
{
	int res = 0; 
	res = min(abs(pa[1] - pa[0]), abs(pa[2] - pa[1]));
	if (pa[0] > pa[1])
		res = -res;
	return res;
}

int main()
{
	int n;
	int d;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin>>pa[i];
		}

		d = getDif();
		int k = pa[0];

		for (int i = 0; pa[i] == k && i < n; i++, k += d);

		cout<<k<<endl;


	}
	return 0;
}