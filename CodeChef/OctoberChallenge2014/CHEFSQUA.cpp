#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

struct Point
{
	int x, y;

	Point(){};
	Point(int a, int b){
		x = a;
		y = b;
	}

	Point inv(){
		return Point(-x, -y);
	}
	Point ort(){
		return Point(-y, x);
	}

	void print(){
		cout<<"Point: "<<x<<", "<<y<<endl;
	}
};

Point operator - (Point a, Point b){
	return Point(a.x - b.x, a.y - b.y);
}

Point operator + (Point a, Point b){
	return Point(a.x+b.x, a.y+b.y);
}

bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Point readPoint(){
	int x, y;
	scanf("%d %d", &x, &y);
	return Point(x, y);
}

bool existe (Point a, set<Point> &p){
	return p.find(a) != p.end();
}

int solve(set<Point> &p, Point a, Point b){
	int res = 2;
	if (existe(a, p))
		res--;
	if (existe(b, p))
		res--;

/*	if (res == 1){
		if (existe(a, p))
			a.print();
		if (existe(b, p))
			b.print();
	}
*/	return res;
}

int main(){

	int n;
	cin>>n;
	set<Point> points;
	set<Point> :: iterator it, jt;

	for(int i = 0; i < n; i++)
		points.insert(readPoint());

	Point a, b;

	if (n < 2){
		cout<<4-n<<endl;
	}
	else{
		int res = 4;
		int pres = 0;

		for(it = points.begin(); it != points.end();){
			a = *it;
			for (jt = (++it); jt != points.end(); jt++){
				
				b = *jt;
/*				cout<<"taken: "<<endl;
				a.print();
				b.print();
				cout<<"------------------"<<endl;
*/				Point dir = (a - b).ort();
/*				cout<<"dir->"<<endl;
				dir.print();
				cout<<"------.------"<<endl;
*/				res = min(res, solve(points, a+dir, b+dir));
				res = min(res, solve(points, a-dir, b-dir));

				if (res == 0) break;
			}

			if (res == 0) break;
		}

		cout<<res<<endl;
	}
	return 0;
}