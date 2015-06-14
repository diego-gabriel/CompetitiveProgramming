#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
#define Point Vector

struct Vector
{
	double x, y;
	Point(){}
	Point(double a, double b){
		x = a;
		y = b;
	}

	double norma(){
		return sqrt(x*x + y*y);
	}

	Vector ortogonal(){
		return Vector(-y, x);
	}
};


bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Vector operator - (Vector a, Vector b){
	return Vector(a.x - b.x, a.y - b.y);
}

Vector operator + (Vector a, Vector b){
	return Vector(a.x+b.x, a.y+b.y);
}

Vector operator * (double e, Vector v){
	return Vector(e*v.x, e*v.y);
}

Vector operator / (Vector v, double c){
	return Vector(v.x / c, v.y / c);
}

double operator * (Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}

int operator ^ (Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}

struct Line
{
	Point p;
	Vector dir;
	Line(){};
	Line(Point a, Vector b){
		p = a;
		dir = b;
	}
};

Point readPoint(){
	double x, y;
	cin>>x>>y;
	return Point(x, y);
}

Vector proyect(Vector a, Vector b){
	return ((a*b)/(b.norma()*b.norma())) * b;
}


Point symmetric(Point p, Line line){

	Point proy = proyect(p-line.p, line.dir);
	return 2*(line.p+proy) - p;
}


bool checkAxis(Line line, set<Point> &points){
	set<Point> :: iterator it;
	bool ok = true;
	for (it = points.begin(); it != points.end() && ok; it++){
		ok = points.find(symmetric(*it, line)) != points.end();
	}

	return ok;
}

int main(){
	int n;

	while (cin>>n && n != -1){
		set <Point> points;

		for (int i = 0; i < n; i++)
			points.insert(readPoint());
		

		set<Point> :: iterator it = points.begin();
		Point a, b;
		a = *it;

		bool ok = false;

		for (it = points.begin(); it != points.end() && !ok; it++){
			b = *it;
			if (b.x == a.x && b.y == a.y)
				continue;

			ok 	= checkAxis(Line(a, (a-b)), points)
			   || checkAxis(Line((a+b)/2, (a-b).ortogonal()), points);
		}
		it = points.begin();
		it++;
		a = *it;

		for (it = points.begin(); it != points.end() && !ok; it++){
			b = *it;
			if (b.x == a.x && b.y == a.y)
				continue;

			ok 	= checkAxis(Line(a, (a-b)), points)
			   || checkAxis(Line((a+b)/2, (a-b).ortogonal()), points);
		}
			

		if (ok)
			cout<<"Y"<<endl;
		else 
			cout<<"N"<<endl;
	}
	return 0;
}