#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		long long x, k, c, s;

		cin>>x>>k;
		c = 1;
		s = 0;
		while (s+c < k){
			s+= c;
			c*=2;
		}
		double len = ((double)x)/((double)c);
		long long rem = k - s;
		double res = (len*rem) + (len*(rem-1));
		printf("%.8lf\n", res/2);
	}
	return 0;
}