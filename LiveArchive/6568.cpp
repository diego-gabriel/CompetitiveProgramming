#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	int test = 0;
	while (cin>>n && n > 0){
		test++;
		double x[n], y[n], m[n];
		double sMass = 0.0;
		double xNum = 0.0;
		double yNum = 0.0;
		for (int i = 0; i < n; i++){
			cin>>x[i]>>y[i]>>m[i];
			sMass += m[i];
			xNum += y[i]*m[i];
			yNum += x[i]*m[i];
		}
		printf("Case %d: %.2f %.2f\n",test, yNum / sMass, xNum / sMass);
	}
	return 0;
}