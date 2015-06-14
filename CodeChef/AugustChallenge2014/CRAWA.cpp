#include <iostream>

using namespace std;

inline int abs(int a){
	return a < 0 ? -a : a;
}

int main(){
	int test;
	cin>>test;

	while (test--){
		int x, y;
		cin>>x>>y;
		string res = "NO";

		
		if (x <= 0 && x % 2 == 0 && abs(y) <= abs(x))
			res = "YES";
		else
		if (x > 0 && x % 2 == 1 && abs(y-1) <= x)
			res = "YES";
		else
		if (y % 2 == 0){
			if (y <= 0 && x >= y && x <= abs(y-1))
				res = "YES";
			if (y > 0 && x <= (y-1) && x >= -y)
				res = "YES";
		}

		cout<<res<<endl;
	}
	return 0;
}