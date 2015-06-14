#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point
{
	double x, y;
	Point(){};
	Point(double a, double b){
		x = a;
		y = b;
	}

	Point operator + (Point p){
		return Point(x+p.x, y+p.y);
	}
	Point operator - (Point p){
		return Point(x-p.x, y-p.y);
	}

	bool operator == (Point p){
		return x == p.x && y == p.y;
	}

};	

bool readPoint(Point &a){
	return cin>>a.x>>a.y;
}

int main(){

	Point a, b, c, d, temp;

	while (readPoint(a)){
		readPoint(b);

		readPoint(c);

		if (b == c){
			swap(a, b);
			readPoint(c);
		}
		else
		if (a == c){
			readPoint(c);
		}
		else{
			readPoint(d);
			if (d == b)
				swap(a, b);
		}

		Point l1, l2;
		l1 = (b - a);
		d = c + l1;

		printf("%.3lf %.3lf\n", d.x, d.y);

	}

	return 0;
}
