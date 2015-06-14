#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	map <double, int> pot;

	double d = 1;
	pot[d] = 0;

	d = 2.0;
	for (int i = 1; d <= 100000000.0; i++)
	{
		pot[d] = i;
		d *= 2.0;
	}

	int n;
	int test = 1;
	while (cin>>n)
	{
		double sum;
		double val;
		for (int i = 0; i < n; i++)
		{

			cout<<"Case "<<test<<": ";
			test++;
			sum = 0;
			for (int k = 0; k < 5; k++)
			{
				cin>>val;
				sum += val;
			}

			double m;
			cin>>m;

			if (sum <= 0) cout<<-1<<endl;
			else
			{
				d = m / sum;
				d -= 0.000001;
				map <double, int> potencia = pot;
				map <double, int> :: iterator it;
				potencia[d];

				it = potencia.find(d);

				int p;

				it++;
				p = (int)(it->second);
				cout<<p<<endl;
			

			}
		}
	}
	return 0;
}