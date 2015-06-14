#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

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

	Point ortogonal(){
		return Point(-y, x);
	}

	Point operator - (Point o){
		return Point(x-o.x, y-o.y);
	}
};

struct Line
{
	double a, b, c;

	Line(){};
	Line(Point p1, Point p2){
		Vector v = (p1 - p2).ortogonal();
		if (fabs(v.y) < EPS){
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		} else {
			a = v.x/v.y;
			b = 1.0;
			c = -a*p1.x - p1.y;
		}
	}
};

bool areParallel(Line line1, Line line2){
	return (fabs(line1.a - line2.a)) < EPS && (fabs(line1.b - line2.b) < EPS);
}

bool areTheSame(Line line1, Line line2){
	return areParallel(line1, line2) && (fabs(line1.c - line2.c) < EPS);
}

Point intersection(Line line1, Line line2){
	double x, y;
	x = (line2.b*line1.c - line2.c*line1.b) / (line1.b*line2.a - line2.b*line1.a);
	if (fabs(line1.b) > EPS)
		y = -line1.c - line1.a*x;
	else
		y = -line2.c - line2.a*x;
	return Point(x, y);
}

struct Segment
{
	Line line;
	Point begin, end;
	Segment(){}
	Segment(Point a, Point b){
		if (a.y < b.y)
			swap(a, b);
		begin = a;
		end = b;
		line = Line(a, b);
	}

	bool intersectionWithLine(Line l, Point &res){

		if (areTheSame(line, l)){
			res = end;
			return false;
		}
		else 
		if (areParallel(line, l)){
			return false;
		}
		else{
			res = intersection(line, l);

			return containsPoint(res);
		}
	}

	bool containsPoint(Point point){
		return begin.y >= point.y && end.y <= point.y; 
	}
};

vector<bool> assigned;
vector<int> memo;
vector<Segment> seg;

Point readPoint(){
	double x, y;
	cin>>x>>y;
	return Point(x, y);
}

int solve(Point source, int line){
	//cout<<"Point ("<<source.x<<", "<<source.y<<") on line "<<line<<endl;
	if (!assigned[line]){
		assigned[line] = true;
		bool found = false;
		Point p, act;
		int res;
		Line l = Line(source, Point(source.x, 0));
		for (int i = 0; i < seg.size(); i++){
			if (!seg[i].intersectionWithLine(l, act)){
				continue;
			}
			if (act.y <= source.y && act.x != seg[i].end.x){
				if (found){
					if (act.y > p.y){
						p = act;
						res = i;
					}
				} else{
					found = true;
					p = act;
					res = i;
				}
			}
		}

		if (!found){
			memo[line] = source.x;
		}
		else{

			memo[line] = solve(seg[res].end, res);
		}
	}
	return memo[line];
}


int main(){
	int nTest;
	cin>>nTest;
	while (nTest--){
		int np;
		cin>>np;
        seg.clear();
		for (int i = 0; i < np; i++){
			seg.push_back(Segment(readPoint(), readPoint()));
		}
		assigned.assign(np+1, false);
		memo.assign(np+1, 0);
		int ns;
		cin>>ns;
		for (int i = 0; i < ns; i++)
		{
			Point source = readPoint();
			assigned[np] = false;
			cout<<solve(source, np)<<endl;
		}
        if (nTest)
            cout<<endl;
	}
	return 0;
}