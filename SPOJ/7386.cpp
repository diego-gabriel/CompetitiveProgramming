#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Segment
{
	long long ini, fin;
	Segment(){};
	Segment(long long a, long long b){
		ini = a;
		fin = b;
	}
};

Segment readSegment(){
	long long a, b;
	cin>>a>>b;
	return Segment(a, b);
}

bool operator < (Segment a, Segment b){
	if (a.ini == b.ini)
		return a.fin < b.fin;
	return a.ini < b.ini;
}

vector <long long> memo;
vector <Segment> segments;

long long bsearch(long long target){
	long long ini, fin, mid;
	ini = -1;
	fin = segments.size();

	while (fin - ini > 1){
		mid = ((fin + ini) / 2);

		if (segments[mid].ini < target)
			ini = mid;
		else
			fin = mid;
	}
	return fin;
}

long long solve(long long n)
{
	if (memo[n] == -1){
		memo[n] = (solve(bsearch(segments[n].fin)) + solve(n+1)) % 100000000;
	}

	return memo[n];
}

int main(){
	long long n;

	while (cin>>n && n != -1){
		segments.clear();
		memo.clear();
		memo.assign(n+1, -1);
		memo[n] = 1;
		for (long long i = 0; i < n; i++){
			segments.push_back(readSegment());
		}
		sort(segments.begin(), segments.end());
		printf("%08d\n", (solve(0)-1+100000000) % 100000000);
	}
	return 0;
}
