#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


double p, a, b, c, d, n;
double f(int k){
	return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main(){
	cin>>p>>a>>b>>c>>d>>n;
	double mx = 0.0;
	double mn = 0.0;
	double res;
	for (int i = 1; i <= n; i++){
		double h = f(i);
		if (h > mx){
			res = max(res, mx-mn);
			mx = mn = h;
		} else if (h < mn){
			mn = h;
		}
	}
	res = max(res, mx-mn);
	printf("%.8lf\n", res);


	return 0;
}