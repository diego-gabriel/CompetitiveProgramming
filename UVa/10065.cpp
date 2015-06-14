#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define Vector Point

struct Point
{
	double x, y;
	Point()
	{
		x = y = 0.0;
	}

	Point(double a, double b)
	{
		x = a;
		y = b;
	}
};

Vector operator - (Point a, Point b)
{
	return Vector(a.x - b.x, a.y - b.y);
}

bool operator < (const Point &a, const Point &b)
{
	bool res;
	if (a.x == b.x)
		res = a.y < b.y;
	else
		res = a.x < b.x;
	return res;
}

double cross(const Vector &a, const Vector &b)
{
	return a.x*b.y - a.y*b.x;
}

vector <Point> convexHull(vector <Point> poly)
{
	int n = poly.size();
	Point hull[2*n];
	int k = 0;
	sort(poly.begin(), poly.end());

	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && cross(hull[k-1] - hull[k-2], poly[i] - hull[k-2]) <= 0) k--;
		hull[k] = poly[i];
		k++;
	}

	for (int i = n-2, t = k; i >=  0; i--)
	{
		while (k > t && cross(hull[k-1] - hull[k-2],poly[i] - hull[k-2]) <= 0) k--;
		hull[k] = poly[i];
		k++;
	}

	vector<Point> res(hull, hull + k - 1);

	return res;
}

double area(vector<Point> det)
{
	double d = 0.0;
	double k = 0.0;

	det.push_back(det[0]);

	for (int i = 0; i < det.size()-1; i++)
		d += det[i].x * det[i+1].y;

	for (int i = 0; i < det.size()-1; i++)
		k += det[i].y * det[i+1].x;

	return fabs(d - k) / 2.0;
}

int main()
{
	int n;
	int test = 0;

	while (cin>>n && n)
	{
		test++;
		vector <Point> poly, hull;
		Point aux;

		for (int i = 0; i < n; i++)
		{
			cin>>aux.x>>aux.y;
			poly.push_back(aux);
		}
		
		hull = convexHull(poly);

		double aPoly, aHull;

		aPoly = area(poly);
		aHull = area(hull);

		double res = aHull - aPoly;

		printf("Tile #%d\nWasted Space = %.2lf ", test, 100.0*(1 - aPoly / aHull));
		cout<<'%'<<endl<<endl;


	}

	return 0;
}