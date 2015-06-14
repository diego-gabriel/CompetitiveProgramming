#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

double res;
double lastK;
double fuelCon;
double nLeaks;
double gasCon;

char com[18];
int k, val;

inline void solve(double actK)
{
	double nK = actK - lastK;

	double fuel = fuelCon + nLeaks*100;
	gasCon += (nK / 100) * fuel; 
	res = max(res, gasCon);

	//cout<<"consumo Actual: "<<gasCon<<endl;
}

int main()
{
	res = 0;
	lastK = 0;
	gasCon = 0;
	nLeaks = 0;
	fuelCon = 0;

	while (scanf("%d", &k) == 1)
	{
		scanf("%s", com);
		solve(k);
		lastK = k;
		if (com[0] == 'F')
		{
			scanf("%s", com);
			scanf("%d", &val);
			if (val != 0)
			{
				fuelCon = val;
			}
			else return 0;
		}
		else
		if (com[0] == 'L')
		{
			nLeaks += 1.0;
		}
		else
		if(com[0] == 'M')
			nLeaks = 0;
		else
		if (com[2] == 's')
		{
			scanf("%s", com);
			gasCon = 0;
		}
		else
		{
			printf("%.3f\n", res);

			res = int(0x7fffffff);
			lastK = 0;
			gasCon = 0;
			nLeaks = 0;
			fuelCon = 0;
			res = 0;
		}
	}
	return 0;
}