#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	long long test;
	cin>>test;

	while (test--)
	{
		int ent, dec;
		int nMin;
		long long actRate;
		int nPlans;
		long long numMin;

		scanf("%d.%d %d %d", &ent, &dec, &nMin, &nPlans);

		numMin = nMin;
		long long bestPlan = 0;
		long long bestRate = ent * 100 + dec;
		long long bestDuration = 1;
		long long activationCost = 0;

		for (long long i = 1; i <= nPlans; i++)
		{
			int dur;
			int c;
			long long duration, cost;
			scanf("%d %d.%d %d", &dur, &ent, &dec, &c);
			cost = c;
			duration = dur;
			cost *= 100;
			actRate = ent * 100 + dec;

			if ((cost + actRate * numMin * duration) * bestDuration <  (activationCost + bestRate * numMin * bestDuration) * duration)
			{
				bestRate = actRate;
				bestDuration = duration;
				activationCost = cost;
				bestPlan = i;
			}
		}

		cout<<bestPlan<<endl;
	}

}