#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	double a, c, b, d, e, f;
	cin>>a>>b>>c>>d>>e>>f;

	double x, y, den;
	den = (2*((b-d)*(e-c) + (f-d)*(c-a)));
	if (den == 0 || (a == e && b == f)){
		cout<<"Impossible"<<endl;
	}
	else {
		if (a == c){
			y = b+d;
			x = (e*e+f*f-c*c-d*d+y*(d-f))/(e-c);
			x /= 2;
			y /= 2;
		}
		else {
			y = ((c-e)*(c*c+d*d-a*a-b*b) + (a-c)*(c*c+d*d-e*e-f*f));
			x = (2*y*(b-d) + c*c*den + d*d*den - a*a*den -b*b*den) / (2*den*(c-a));
			y /= den;
		}
		printf("%.12lf %.12lf\n", x, y);
	}
	return 0;
}