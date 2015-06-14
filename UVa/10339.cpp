#include <iostream>
#include <cstdio>

using namespace std;

#define DAY 60*60*24

int main(){
	unsigned int m, k;

	while (cin>>m>>k){
		cout<<m<<" "<<k<<" ";

		unsigned int d = m < k ? k-m : m - k;

		unsigned int t = ((43200*(DAY - m)) / d) % 43200 + 30;

		printf("%02d:%02d\n", (t/3600%12 == 0 ? 12 : t / 3600  % 12), t/60%60);

	}
	return 0;
}