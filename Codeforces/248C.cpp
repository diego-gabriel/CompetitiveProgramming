#include <iostream>
#include <cstdio>

using namespace std;

double y1, y2, yw, xb, yb, r;

double find(double y)
{
	return (xb*(yw-y))/(2*yw - yb - y);
}

int main()
{
	cin>>y1>>y2>>yw>>xb>>yb>>r;

	y1 += r;

	double R = (r*(yw - y1)) / (y2 - y1);

	cout<<R<<endl;

	yw -= r;
	y2 -= r;

	double res;

	if (y1 > y2) 
	{
		//cout<<"aca"<<endl;
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		double z = find(y1);
		cout<<z<<endl;

		if (z > R && z < xb)
		{
			res = z;
		}
		else {
			cout<<"AQ"<<-1<<endl;
			return 0;
		}

	}

	printf("%.8f\n", res);

	return 0;
}