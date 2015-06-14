#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
struct Point
{
	double x;
	double y;

	Point(){}
	Point(double a, double b){
		x = a;
		y = b;
	}

	double mod(){
		return sqrt(x*x + y*y);
	}
};

Point operator + (Point a, Point b){
	return Point(a.x+b.x, a.y+b.y);
}
Point operator - (Point a, Point b){
	return Point(a.x-b.x, a.y-b.y);
}
Point operator / (Point a, double b){
	return Point(a.x/b, a.y/b);
}


int main(){

	int x, y, r1, r2;
	Point c1, c2;
	cin>>x>>y>>r1;
	c1 = Point(x, y);
	cin>>x>>y>>r2;
	c2 = Point(x, y);

	double dist = (c1-c2).mod();
	if (r1 > r2)
		swap(r1, r2);

	if (dist > r1+r2){
		printf("%.9lf\n", (dist-r1-r2)/2.0);
	} else {
		if (dist+r1 < r2){
			printf("%.9lf\n", (r2-dist-r1)/2);
		} else { 
			cout<<0.0<<endl;
		}
	}
	return 0;
}