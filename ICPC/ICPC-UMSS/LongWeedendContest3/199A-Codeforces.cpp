#include <iostream>
#include <map>

using namespace std;

struct Sol
{
	int a;
	int b;
	int c;
	
	Sol(int d, int e, int f)
	{
		a = d;
		b = e;
		c = f;
	}
	
	
	Sol(){};
	
	
	int val()
	{
		return a + b + c;
	}
	
	void print()
	{
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
};

int main()
{
	map <int, Sol> res;
	
	int n;
	cin>>n;
	
	res[0] = Sol(0, 0, 0);
	res[1] = Sol(0, 0, 1);
	res[2] = Sol(0, 0, 1);
	
	int a, b, f;
	
	a = b = 1;
	int i;
	for (i = 3; f < n; i++)
	{
		f = a + b;
		a = b;
		b = f;
		res[i] = Sol(res[i-3].val(), res[i-2].val(), res[i-2].val());
	}
	if (n == 0)
	res[0].print();
	else if (n == 1) res[1].print();
	else
	res[i-1].print();
	return 0;
}
