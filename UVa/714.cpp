#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int scr[501];

int main()
{
	int n;
	cin>>n;
	
	while (n--)
	{
		int m, k, suma = 0;
		cin>>m>>k;
		
		for (int i = 0; i < m; i++)
			cin>>scr[i], suma += scr[i];
		for (int i = 1; i < m; i++)
			scr[i] += scr[i-1];
		
		double target = (double (suma)) / k;
		double dif = target;
	    double lastDif = target;
		
		cout<<target<<endl;
		
		cout<<scr[0];
		dif = fabs(target - scr[0]);
		
		for (int i = 1; i < m; i++)
		{
			lastDif = dif;
			dif = fabs(target - scr[i]);
			
			cout<<"a: "<<lastDif<<" "<<dif<<" "<<target<<endl;
			if (lastDif < dif)
			{
				target += target;
				cout<<" /";
			}
			cout<<" "<<scr[i] - scr[i-1];
		}	
		cout<<endl;
	}
	
	return 0;
}
