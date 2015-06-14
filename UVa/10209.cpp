#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define PI 3.14159265358979323846

int main()
{
	double l, x, y, z;

	while (cin>>l)
	{
		z = l*l*(1.0 - (1.0/6.0)*PI - (sin(PI / 3.0) / 2.0));
		y = l*l - l*l*PI/4.0 - 2.0*z;
		x = l*l - 4.0*y - 4.0*z;

		printf("%.3f %.3f %.3f\n", x, 4*y, 4*z);
	}
	return 0;
}