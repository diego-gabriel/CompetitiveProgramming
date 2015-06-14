#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define Vector Point
#define EPS 1e-9
struct Point
{
	double x, y;
	Point(){};
	Point(double a, double b){
		x = a;
		y = b;
	}

	Vector ortogonal(){
		return Vector(-y, x);
	}

	Point operator - (Point &other){
		return Point(x - other.x, y - other.y);
	}
};

struct Line
{
	double A, B, C;
	Line(){};
	Line(Point p1, Point p2){			
		Vector v = (p1-p2).ortogonal();
		if (fabs(v.y) < EPS){
			A = 1.0;
			B = 0.0;
			C = -p1.x;
		} else {
			A = v.x/v.y;
			B = 1.0;
			C = -A*p1.x - p1.y;
		}
	}

};

bool areParallel(Line line1, Line line2){
	return (fabs(line1.A - line2.A)) < EPS && (fabs(line1.B - line2.B) < EPS);
}

bool areTheSame(Line line1, Line line2){
	return areParallel(line1, line2) && (fabs(line1.C - line2.C) < EPS);
}

Point intersection(Line line1, Line line2){
	double x, y;
	x = (line2.B*line1.C - line2.C*line1.B) / (line1.B*line2.A - line2.B*line1.A);
	if (fabs(line1.B) > EPS)
		y = -line1.C - line1.A*x;
	else
		y = -line2.C - line2.A*x;
	return Point(x, y);
}

Point readPoint(){
	double x, y;
	scanf("%lf %lf", &x, &y);
	return Point(x, y);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--){
		Point p1, p2, p3, p4;
		double x, y;
		Line l1, l2;

		p1 = readPoint();
		p2 = readPoint();
		p3 = readPoint();
		p4 = readPoint();

		l1 = Line(p1, p2);
		l2 = Line(p3, p4);

		if (areTheSame(l1, l2))
			printf("LINE\n");
		else
		if (areParallel(l1, l2))
			printf("NONE\n");
		else{
			Point res = intersection(l2, l1);
			printf("POINT %.2lf %.2lf\n", res.x, res.y);
		}
	}
	printf("END OF OUTPUT\n");
}