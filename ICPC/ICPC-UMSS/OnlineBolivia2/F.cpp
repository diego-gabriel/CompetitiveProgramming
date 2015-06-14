#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	while (n--)
	{
		int l, k;
		string cad;
		int acum = 0;
		int rigth, left;
		rigth = left = 0;
		cin>>l;
		bool izq, der;
		izq = der = false;
		for (int i = 0; i < l; i++)
		{
			cin>>cad;
			k = 0;
			while (k < 3 && cad[k] != 'X')
				k++;
			if (k == 3) acum += 3;
			else
			{
				if (k == 0)
				{
					rigth += acum;
					acum = 0;
					rigth += 2;
					der = true;
					izq = false;
				}else
				if (k == 1)
				{
					left++;
					rigth++;
				}else
				{
					left += acum;
					acum = 0;
					left += 2;
					der = false;
					izq = true;
				}
			}
		}
		
		if (der) rigth += acum;
		if (izq) left += acum;
		
		cout<<left<<" "<<rigth<<endl;
		
	}
	
	return 0;
}
