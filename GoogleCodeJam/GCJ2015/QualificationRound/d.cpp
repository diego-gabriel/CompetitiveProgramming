#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int x, r, c;
	int t;

	cin>>t;
	for (int test = 1; test <= t; test++){
		cin>>x>>r>>c;
		bool rich = r*c % x != 0;
		rich = rich || min(r, c) < (x+1)/2 || max(r, c) < x/2 +1;
		rich = rich || x >= 7;
		rich = rich || max(r, c) < x;
		rich = rich || (x >= 4 && min(r, c) <= 2);

		cout<<"Case #"<<test<<": ";
		if (rich)
			cout<<"RICHARD"<<endl;
		else
			cout<<"GABRIEL"<<endl;

	}

	return 0;
}