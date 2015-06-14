#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int r, x, y, x1, y1;
	cin>>r>>x>>y>>x1>>y1;
	double a = x - x1;
	double b = y - y1;
	double dist = sqrt(a*a + b*b);
	int res = 0;
	while (dist > 0){
		dist -= 2.0*r;
		res++;
	}
	cout<<res<<endl;



	return 0;
}