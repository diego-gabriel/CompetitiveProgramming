#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define Point Vector

struct Vector
{
	double x, y;

	Vector(){x = y = 0.0;};
	Vector(double a, double b){
		x = a;
		y = b;
	}

	double norma(){
		return sqrt(x*x + y*y);
	}

	Vector ort(){
		return Vector(-y, x);
	}


	void print(){
		printf("%.4lf\n%.4lf\n", x, y);
	}
};

double operator * (Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}

double operator ^ (Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}

Vector operator + (Vector a, Vector b){
	return Vector(a.x + b.x, b.y + a.y);
}

Vector operator - (Vector a, Vector b){
	return Vector(a.x - b.x, a.y - b.y);
}

Vector operator * (double x, Vector v){
	return Vector(x*v.x, x*v.y);
}

Vector operator / (Vector v, double y){
	return Vector(v.x / y, v.y / y);
}

struct Segment
{
	Point begin, end;
	Segment (Point a, Point b){
		begin = a;
		end = b;
	}
	Segment(){};
	bool contains(Point p){
		double segSize = (end - begin).norma();
		bool res =  segSize >= (p - begin).norma() && 
				    segSize >= (p - end).norma();
		return res;
	}
};


Point proyection(Segment seg, Point p){
	Vector res, A, B;

	A = p - seg.begin;
	B = seg.end - seg.begin;

	res = ((A*B) * B) / (B.norma() * B.norma());

	return res + seg.begin;
}

double closest ( Segment &seg,  Point &M, Point &res){
	double dis;
	Point a, b, c;
	a = seg.begin;
	b = seg.end;
	c = proyection(seg, M);
	if (seg.contains(c)){

		res = c;
		dis = (c - M).norma();
	}
	else{
		if ((a - M).norma() <= (b-M).norma()){
			res = a;
			dis = (a - M).norma();
		}
		else{
			res = b;
			dis = (b - M).norma();
		}
	}

	return dis;
}

int main(){

	Point M;

	double x, y;

	while (cin>>x>>y){
		M = Point(x, y);
		int n;
		cin>>n;
		Point p0;
		cin>>x>>y;
		Segment seg[n];
		p0 = Point(x, y);
		for (int i = 0; i < n; i++){
			cin>>x>>y;
			seg[i] = Segment(p0, Point(x, y));
			p0 = Point(x, y);
		}

		double dis, d;
		Point res, r;
		dis = closest(seg[0], M, res);

		for (int i = 1; i < n; i++){
			d = closest(seg[i], M, r);
			if (d < dis){
				dis = d;
				res = r;
			}
		}

		res.print();
	}

	return 0;
}