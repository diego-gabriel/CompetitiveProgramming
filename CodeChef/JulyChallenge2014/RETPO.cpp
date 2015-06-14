#include <iostream>

using namespace std;

int abs(int a){
	return a < 0 ? -a : a;
}

int max (int a, int b){
	return a < b ? b : a;
}

int main(){
	int t;
	cin>>t;
	int x;
	int y;

	while (t--){
		cin>>x>>y;
		x = abs(x);
		y = abs(y);
		int m = min(x, y);
		x -= m;
		y -= m;
		int r = 0;
		if (y == 0)
			r = (x % 2 == 0) ? 2*x : 2*x+1;
		else
			r = (y % 2 == 0) ? 2*y : 2*y-1;

		cout<<r+2*m<<endl;
	}
	return 0;
}