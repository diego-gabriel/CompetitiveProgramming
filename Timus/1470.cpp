#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 130

long long t[MAX][MAX][MAX];

long long add(long long v, long long x, long long y, long long z){
	//cout<<"adding: "<<v<<endl;
	for(long long i = x; i < MAX; i |= i+1)
		for(long long j = y; j < MAX; j |= j+1)
			for(long long k = z; k < MAX; k |= k+1){
				t[i][j][k] += v;
			}
}

long long get(long long x, long long y, long long z){
	long long res = 0;
	for(long long i = x; i >= 0; i = (i & (i+1)) - 1)
		for(long long j = y; j >= 0; j = (j & (j+1)) - 1)
			for(long long k = z; k >= 0; k = (k & (k+1)) - 1)
				res += t[i][j][k];
	//cout<<"res> "<<res<<endl;
	return res;
}

long long sum(long long a, long long b, long long c, long long x, long long y, long long z){
	//cout<<"summing: "<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<" "<<endl;
	return get(x, y, z) - get(a-1, y, z) - get(x, b-1, z) - get(x, y, c-1) - get(a-1, b-1, c-1) + get(a-1, b-1, z) + get(a-1, y, c-1) + get(x, b-1, c-1); 
}

int main(){
	memset(t, 0, sizeof(t));

	long long n, a, b, c, x, y, z, v, m;

	scanf("%lld", &n);
	while(scanf("%lld", &m) && m != 3){
		//cout<<"pasi "<<m<<endl;
		if (m == 2){
			//cout<<"this"<<endl;
			scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &x, &y, &z);
			x++;y++;z++;a++;b++;c++;
			printf("%lld\n", sum(a, b, c, x, y, z));
		//	//cout<<get(x, y, z)<<endl;
		} else {
			scanf("%lld %lld %lld %lld", &x, &y, &z, &v);
			add(v, x+1, y+1, z+1);
		}
	}
}