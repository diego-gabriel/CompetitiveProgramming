#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct Point
{	
	int x;
	int y;
	bool killed;

	Point(){ x = y = killed = false;}
	Point(int i, int j){
		killed = false;
		x = i;
		y = j;
	}
};

int main(){
	int n, x, y;
	cin>>n>>x>>y;
	Point points[n+1];
	points[0] = Point(x, y);

	for (int i = 1; i <= n; i++){
		cin>>x>>y;
		points[i] = Point(x, y);
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (!points[i].killed){
			res++;
			Point dir = Point(points[i].x - points[0].x,
						  	  points[i].y - points[0].y);
			points[i].killed = true;
			for (int j = 1; j <= n; j++){
				if (points[j].killed)
					continue;
				Point otherDir = Point(points[j].x - points[0].x,
						  	  points[j].y - points[0].y);
				if (otherDir.x * dir.y == otherDir.y * dir.x)
					points[j].killed = true;
			}
		}
	}

	cout<<res<<endl;
	return 0;
}