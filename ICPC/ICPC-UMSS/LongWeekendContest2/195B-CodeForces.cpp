#include <iostream>
#include <set>

using namespace std;

int n, m;
	
int abs(int a)
{
	return a < 0 ? -a : a;
}	

struct Basket
{
	int in;
	int ID;
	int val;
	Basket(){};
	Basket(int i)
	{
		ID = i;
		in = 0;
		val = abs((m+1) - ID*2);
	}
	void add()
	{
		in++;
	}
};

bool operator < (Basket a, Basket b)
{
	bool res;
	if (a.in == b.in)
	{
		if (b.val == a.val)
		{
			res = a.ID < b.ID;
		} else
		res = a.val < b.val;
	} else
	res = a.in < b.in;
	return res;
}
struct classcomp {
  bool operator() (const Basket& lhs, const Basket& rhs) const
  {return lhs<rhs;}
};


set <Basket, classcomp> baskets;

int main()
{
	cin>>n>>m;
	
	Basket bas;
	
	for (int i = 1; i <= m; i++)
	{
		bas = Basket(i);
		baskets.insert(bas);
	}
	
	set <Basket, classcomp> :: iterator it;
	
	for (int i = 1; i <= n; i++)
	{
		it = baskets.begin();
		bas = *it;
		baskets.erase(baskets.begin());
		bas.add();
		cout<<bas.ID<<endl;
		baskets.insert(bas);
	}
	
	return 0;
}
