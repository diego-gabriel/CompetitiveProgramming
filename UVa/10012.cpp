#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int id[8];
double r[8];

double solve(double hip, double cat)
{
	return sqrt(hip*hip - cat*cat);
}

double calcBox(int n)
{
	double res = 0.0;
	double disUn[8];
	disUn[0] = 2*r[id[0]];
	res += r[id[0]];
	res += r[id[n-1]];

	for (int i = 1; i < n; i++)
	{
		double rad1 = r[id[i]];
		double rad2 = r[id[i-1]];
		double cat = solve(rad1 + rad2, fabs(rad1 - rad2));

		for (int j = i-1; j >= 0; j--)
		{
			if (hipo())
		}

	}

	return res;
}

int main()
{
	int nTest;
	cin>>nTest;

	while(nTest--)
	{
		int n;

		cin>>n;

		for (int i = 0 ; i < n; i++)
		{	
			id[i] = i;
			cin>>r[i];
		}

		double res = calcBox(n);

		do
		{
			res = min(calcBox(n), res);

		} while (next_permutation(id, id + n));

		printf("%.3lf\n", res);
	}

	return 0;
}

/*
 Sample Input 


3
3 2.0 1.0 2.0
4 2.0 2.0 2.0 2.0
3 2.0 1.0 4.0

Sample Output 


9.657
16.000
12.657

*/