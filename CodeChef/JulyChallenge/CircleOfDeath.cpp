#include <iostream>
#include <vector>

using namespace std;

struct Tripla
{
	int valor[3];
	Tripla(){}
	
	void print()
	{
		cout<<valor[0]<<" "<<valor[1]<<" "<<valor[2]<<endl;
	}
};

Tripla decode (int a)
{
	Tripla res;
	
	int i = 0;
	int n = 0;
	while (a)
	{
		if (a & 1)
		{
			res.valor[n] = i;
			n++;
		} 
		i++;
		a = a >> 1;
	}
	
	return res;
}

vector <Tripla> comb(int n)
{
	vector <Tripla> res;
	
	int a, c, b;
	a = 1<<n;
	
	while (a > 3)
	{
		b = a >> 1;
		
		while (b > 1)
		{
			c = b >> 1;
			
			while (c)
			{
				res.push_back(decode(a | b | c));
				c = c >> 1;
			}
			
			b = b >> 1;
		}
		
		a = a >> 1;
	}
	
	return res;
}

int main()
{
	int t, n, x, y;
	
	cin>>t;
	while (t--)
	{
		cin>>n;
		
		vector <Tripla> combinaciones = comb(n-1);
		
		for (int i = 0; i < combinaciones.size(); i++)
		{
			combinaciones[i].print();
		}
	}
	return 0;
}
