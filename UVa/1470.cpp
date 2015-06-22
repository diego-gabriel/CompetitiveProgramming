#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 130

long long t[MAX][MAX][MAX];

long long add(long long v, long long x, long long y, long long z){
	for(long long i = x; i < MAX; i |= i+1)
		for(long long j = y; j < MAX; j |= j+1)
			for(long long k = z; k < MAX; k |= k+1)
				t[i][j][k] += v;
}

long long get(long long x, long long y, long long z){
	long long res = 0;
	for(long long i = x; i < MAX; (i & (i+1)) - 1)
		for(long long j = y; j < MAX; (j & (j+1)) - 1)
			for(long long k = z; k < MAX; (k & (k+1)) - 1)
				res += t[i][j][k];
}

long long sum(long long a, long long b, long long c, long long x, long long y, long long z){
	return get(x, y, z) - get(a-1, y, z) - get(x, b-1, z) - get(x, y, c-1) - get(a-1, b-1, c-1) + get(a-1, b-1, z) + get(a-1, y, c-1) + get(x, b-1, c-1); 
}

int main(){
	memset(t, 0, sizeof(t));

	long long n, a, b, c, x, y, z, v, m;

	scanf("%lld", &n);
	while(scanf("%lld", &m) && m != 3){
		if (m == 2){
			scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &x, &y, &z);
			printf("%lld\n", sum(a, b, c, x, y, z));
		} else {
			scanf("%lld %lld %lld %lld", &x, &y, &z, &v);
			add(v, x, y, z);
		}
	}
}