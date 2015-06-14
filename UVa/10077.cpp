#include <iostream>
#include <cstring>

using namespace std;

struct Fraccion
{
	int num, den;
	Fraccion () {num = den = 0;}
	Fraccion (int a, int b)
	{
		num = a;
		den = b;
	}

	double valor()
	{
		return double (num) / double(den);
	}
};

Fraccion operator + (const Fraccion &a, const Fraccion &b)
{
	return Fraccion(a.num + b.num, a.den + b.den);
}

bool operator == (const Fraccion &a, const Fraccion &b)
{
	return a.num == b.num && a.den == b.den;
}

string solve(Fraccion left, Fraccion center, Fraccion rigth, Fraccion &target)
{
	return center == target ? "" : (target.valor() < center.valor() ? "L" + solve(left, left + center, center, target) : "R" + solve(center, center + rigth, rigth, target)); 
}

int main()
{
	Fraccion target;
	while (cin>>target.num>>target.den && (target.num != 1 || target.den != 1))
	{
		cout<<solve(Fraccion(0, 1), Fraccion(1, 1), Fraccion(1, 0), target)<<endl;
	}
	return 0;
}