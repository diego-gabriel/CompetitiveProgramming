#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define EPS 1e-9
#define Vector Point

struct Point
{
	double x, y;
	Point(){};
	Point(double a, double b){
		x = a;
		y = b;
	}

	Point operator - (Point o){
		return Point(x-o.x, y-o.y);
	}

	Point operator + (Point o){
		return Point(x+o.x, y+o.y);
	}

	Point operator / (int d){
		return Point(x/d, y/d);
	}

	double operator * (Point o){
		return fabs(x*o.y - y*o.x);
	}

	void multiply(double a){
		x *= a;
		y *= a;
	}

};

bool readPoint(Point &p){
	double x, y;
	bool res = cin>>x>>y;
	if (res)
		p = Point(x, y);
	return res;
}

bool isZero(Point a){
	return a.x == 0.0 && a.y == 0.0;
}

int main(){
	Point A, B, C, D, E, F, H, G;
	int test = 0;
	while (readPoint(A)){
		readPoint(B);
		readPoint(C);
		readPoint(D);
		readPoint(E);
		readPoint(F);

		Point low, high, mid, AB;
		low = A;
		high = C;
		AB = B-A;
		double targetArea = fabs(((D-F)*(E-F)) / 2); 
		mid = (low + high) / 2;
		double area = fabs((mid - A) * AB);
		//cout<<"area "<<area<<endl;
		while (area < targetArea){
			Vector dir = high - A;
			dir.multiply(2);
			high = A + dir;
			mid = (low + high) / 2;
			area = fabs((mid - A) * AB);
		}

		
		int times = 0;

		while (fabs((area = fabs((mid - A) * AB))-targetArea) >= EPS && times < 2000){
			//printf("x: %.4lf, y: %.4lf | area: %.4lf | target: %.4lf\n", mid.x, mid.y, area, targetArea);
			if (area < targetArea){
				low = mid;
				mid = (low+high) / 2;
			}
			else {
				high = mid;
				mid = (low+high) / 2;
			}
			times++;
		}

		H = mid;
		G = H + AB;
		test++;
		//cout<<test<<endl;
		if (!isZero(H) && !isZero(G))
			printf("%.3lf %.3lf %.3lf %.3lf\n", G.x, G.y, H.x, H.y);
	}
	return 0;
}