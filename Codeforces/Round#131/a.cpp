#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	int n, m;
	cin>>n>>m;
	int res = 0;
	int b;
	for (int a = 0; a*a <= n; a++){
		b = n - a*a;
		if (b >= 0 && (a + b*b) == m)
			res++;
	}

	cout<<res<<endl;

	return 0;
}