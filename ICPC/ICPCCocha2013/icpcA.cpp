#include <iostream>

using namespace std;

int main()
{
	int n;

	while (cin>>n && n)
	{
		int v[n];

		for (int i = 0; i < n; i++)
			cin>>v[i];

		int bestIni, bestFin, actIni, actFin, best, actBest;

		bestIni = bestFin = -1;
		best = 0;

		actBest = actIni = actFin = 0;

		for (actFin = 0; actFin < n; actFin ++)
		{
			actBest += v[actFin];

			if (actBest >= best)
			{
				best = actBest;
				bestIni = actIni;
				bestFin = actFin;
			}
			
			if (actBest <= 0)
			{
				actIni = actFin +1;
				actBest = 0;
			}
		}

		cout<<best<<" "<<bestIni<<" "<<bestFin<<endl;
	}
	return 0;
}