#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
	Point(){};
	Point(double a, double b){
		x = a;
		y = b;
	}

	Point operator - (Point &o){
		return Point(x-o.x, y-o.y);
	}

	double dist(){
		return sqrt(x*x+y*y);
	}
};

bool orden (Point a, Point b){
	return a.x > b.x;
}

Point readPoint(){
	double x, y;
	cin>>x>>y;
	return Point(x,y);
}

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int n;
		cin>>n;
		Point points[n];
		for (int i = 0; i < n; i++){
			points[i] = readPoint();
		}
		sort(points, points+n, orden);
		double res = 0.0;
		Point last = Point(0, 0);
		for (int i = 0; i < n-1; i+=2){
			Point low = points[i];
			Point peak = points[i+1];
			if (peak.y > last.y){
				//cout<<"last: "<<last.y<<endl;
				//cout<<"peak: "<<peak.y<<" "<<peak.x<<endl;
				//cout<<"low: "<<low.y<<" "<<low.x<<endl;
				double tmp = (peak-low).dist();
				double rat = (peak.y - low.y) / (last.y - low.y);
				//cout<<tmp<<" "<<rat<<endl;

				res += (tmp * (peak.y-last.y) / (peak.y-low.y));
				last = peak;
			}
		}

		printf("%.2lf\n", res);

	}


	return 0;
}