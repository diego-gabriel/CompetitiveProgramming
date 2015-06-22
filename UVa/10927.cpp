#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Point
{
	double x, y, h;
	Point(){}
	Point(double a, double b, double c){
		x = a;
		y = b;
		h = c;
	}

	void print(){
		cout<<"x = "<<x<<", y = "<<y;
	}

};

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}

bool operator < (Point a, Point b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	map<long long, set<Point> > points;

	int n;
	int test = 0;
	while (cin>>n && n){
		points.clear();
		long long x, y, h;
		for(int i = 0; i < n; i++){
			cin>>x>>y>>h;
			long long g = gcd(x, y);
			points[(x/g)*2000000 + (y/g)].insert(Point(x, y, h));
		}

		set<Point> :: iterator it;
		map<long long, set<Point> > :: iterator t;
		set<Point> res;
		double last = 200000;
		Point p;
		Point lastP;

		for(t = points.begin(); t != points.end(); t++){
			set<Point> s1, s2;

			for(it = (t->second).begin(); it != (t->second).end(); it++){
				p = *it;
				if (p.x < 0)
					s1.insert(Point(-p.x, p.y, p.h));
				else
					s2.insert(p);
			}
			last = -1.0;
			for(it = s1.begin(); it != s1.end(); it++){
				p = *it;
				if (p.h <= last)
					res.insert(Point(-p.x, p.y, 0));
				else
					last = p.h;
			}
			last = -1.0;
			for(it = s2.begin(); it != s2.end(); it++){
				p = *it;
				if (p.h <= last)
					res.insert(p);
				else
					last = p.h;
			}
		}

		test++;

		cout<<"Data set "<<test<<":"<<endl;
		if (res.size() == 0)
			cout<<"All the lights are visible."<<endl;
		else {
			cout<<"Some lights are not visible:"<<endl;
			bool fst = true;
			for(it = res.begin(); it != res.end(); it++){
				if (!fst)
					cout<<";"<<endl;
				p = *it;
				p.print();
				fst = false;
			}
			cout<<"."<<endl;
		}

	}

	return 0;
}