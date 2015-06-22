#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

struct Point
{
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}
};

bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int operator * (Point a, Point b){
	return a.x*b.y - a.y*b.x;
}
Point operator - (Point a, Point b){
	return Point(a.x-b.x, a.y-b.y);
}

int abs(int a){
	return a < 0 ? -a : a;
}

int area(Point a, Point b){
	return abs(a * b);
}

struct Triangle
{
	set<Point> p;
	Triangle(){}
	Triangle(Point a, Point b, Point c){
		p.insert(a);
		p.insert(b);
		p.insert(c);
	}
};

bool operator < (Triangle a, Triangle b){
	return a.p < b.p;
}

int main(){
	int n;
	cin>>n;
	Point p[n];
	for(int i = 0; i < n; i++){
		cin>>p[i].x>>p[i].y;
	}

	Triangle tt;
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				if (area(p[i]-p[k], p[i]-p[j]))
					res++;
			}
		}	
	}

	cout<<res<<endl;
	return 0;
}