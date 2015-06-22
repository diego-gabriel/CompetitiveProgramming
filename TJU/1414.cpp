#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

#define PI acos(-1)
#define EPS 10e-9

#define Point Vector

struct Vector
{
	double x, y;
	Point(){}
	Point(double a, double b){
		x = a;
		y = b;
	}
	 //retorna la norma o tamanho del vector
	double n(){
		return sqrt(x*x + y*y);
	}
	//retorna vector ortogonal.
	Vector ortogonal(){
		return Vector(-y, x);
	}
	//retorna vector unitario |v| == 1
	Point u(){
		return Point(x/n(), y/n());
	}

	void read(){
		cin>>x>>y;
	}
};

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

bool operator == (Point a, Point b){
	return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

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
Vector operator * (Vector v, double e){
	return Vector(e*v.x, e*v.y);
}

Vector operator / (Vector v, double c){
	return Vector(v.x / c, v.y / c);
}
//producto interno
double operator * (Vector a, Vector b){
	return a.x*b.x + a.y*b.y;
}
//producto cruz
double operator ^ (Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}
//proyeccion ortogonal del vector a sobre b
Vector proyect(Vector a, Vector b){
	return ((a*b)/(b.n()*b.n())) * b;
}
//devuelve el punto p al otro lado de line como eje de simetria
Point symmetric(Point p, Line line){

	Point proy = proyect(p-line.p, line.dir);
	return 2*(line.p+proy) - p;
}
//si las lineas son paralelas
bool areParallel(Line a, Line b){
	return (a.dir ^ b.dir) == 0.0;
}
//area entre los puntos p1, p2 y p3
double area(Point p1, Point p2, Point p3){
	return fabs((p1-p2) ^ (p3-p2));
}
//angulo entre v1 y v2  a^b = |a||b|sin(x)
double ang(Vector v1, Vector v2){
	return asin((v1^v2)/(v1.n()*v2.n()));
}
//distancia de p a la recta l
double distTo(Point p, Line l){
	return ((l.p - p)^l.dir) / l.dir.n(); 
}
//interseccion de l1 y l2
Point lineIntersection(Line l1, Line l2){
	Vector v3 = l1.p-l2.p;
	return (proyect(v3, l2.dir).u() * fabs(l1.dir ^ v3)/l1.dir.n()) + l2.p;
}
//mediatriz entre p1 y p2
Line mediatriz(Point p1, Point p2){
	return Line((p1+p2)/2.0, (p1-p2).ortogonal());
}

Vector rotate(double ang, Vector p){
	return Point(p.x*cos(ang) - p.y*sin(ang), p.x*sin(ang)+p.y*cos(ang));
}

int main(){
	int t;
	cin>>t;
	while (t--){
		Point p1, p2, p3;
		p1.read();
		p2.read();
		p3.read();

		Line l1, l2;

		l1 = mediatriz(p1, p2);
		l2 = mediatriz(p2, p3);

		Point center = lineIntersection(l1, l2);
		Vector v = p1-center;

		bool ok = false;
		int n;
		for(n = 3; !ok; n++){
			bool a, b, c;
			cout<<"n: "<<n<<endl;
			a = b = c = false;

			for(int i = 0; i < n; i++){
				double ang = 2.0*PI*(double)i/(double)n;
				Point rotated = rotate(ang, v) + center;
				cout<<"X: "<<rotated.x<<" Y: "<<rotated.y<<endl;
				a = a || p1 == rotated;
				b = b || p2 == rotated;
				c = c || p3 == rotated;
			}

			ok = a && b && c;
		}
		n--;
		cout<<n<<endl;
	}
	return 0;
}