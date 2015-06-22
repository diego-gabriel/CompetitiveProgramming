#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	double x1, x2, y1, y2;

	while(cin>>x1>>y1>>x2>>y2){

		double x, y;
		x = (x1-x2)/2.0;
		y = (y1-y2)/2.0;

		printf("%.10lf %.10lf %.10lf %.10lf\n", x2+x-y, y2+y+x, x2+x+y, y2+y-x);
	}
	return 0;
}