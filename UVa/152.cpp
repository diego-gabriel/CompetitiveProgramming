#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

struct Point
{
	double x, y, z;
	Point(){x = y = z = 0.0;};
	Point(double a, double b, double c){
		x = a;
		y = b;
		z = c;
	}

	double operator * (const Point &p){
		return sqrt(pow(x-p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
	}
};

int main(){
	double x, y, z;
	vector <double> dist;
	vector <Point> points;
	int res[10];
	memset(res, 0, sizeof(res));

	while (cin>>x>>y>>z && (x != 0 || y != 0 || z != 0)){
		points.push_back(Point(x, y, z));
	}

	for (int i = 0; i < points.size(); i++){
		double minDist = 1000000000;
		for (int j = 0; j < points.size(); j++){
			if (i != j){
				minDist = min(minDist, points[i]*points[j]);
			}
		}

		if (minDist < 10.0)
			res[(int)minDist]++;
	}

	for (int i = 0; i < 10; i++)
		printf("%4d", res[i]);
	printf("\n");

	return 0;
}