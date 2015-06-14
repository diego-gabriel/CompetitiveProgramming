#include <iostream>

using namespace std;

int main(){
	int a, b, c, n;
	cin>>n;

	for (int test = 1; test <= n; test++){
		cin>>a>>b>>c;
		int res;
		if (a <= b && a <= c)
			res = min(b, c);
		else
		if (b <= a && b <= c)
			res = min(a, c);
		else
		// c es el menor
			res = min(a, b);

		cout<<"Case "<<test<<": "<<res<<endl;
	}
	return 0;
}