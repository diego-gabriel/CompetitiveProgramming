#include <iostream>
#include <cmath>

using namespace std;

double a1, b1, a2, b2, a3, b3;

double dist(double a, double b, double i, double j)
{
	return sqrt((a-i)*(a-i) + (b-j)*(b-j));
}

double semiP()
{
	return (dist(a1, b1, a2, b2) + dist(a2, b2, a3, b3) + dist(a1, b1, a3, b3)) / 2;
}

double calcArea()
{
	double s = semiP();
	return sqrt(s*(s-dist(a1, b1, a2, b2))*(s-dist(a3, b3, a2, b2))*(s-dist(a1, b1, a3, b3)));
}

int main()
{
	double minimo, maaimo;
	minimo = 20000000.0;
	maaimo = 0.0;

	int minIn = 0;
	int maaIn = 0;

	int n;
	cin>>n;

	double area;

	for (int i = 1; i <= n; i++)
	{
		cin>>a1>>b1>>a2>>b2>>a3>>b3;
		area = calcArea();
		if (area >= maaimo)
		{
			maaimo = area;
			maaIn = i;
		}

		if (area <= minimo)
		{
			minimo = area;
			minIn = i;
		}
	}

	cout<<minIn<<" "<<maaIn<<endl;

	return 0;
}