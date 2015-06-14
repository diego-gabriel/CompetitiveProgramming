#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <long long> toVec(long long n){
	vector <long long> res;

	while (n){
		res.push_back(n%10);
		n /= 10;
	}

	for (long long i = 0; i < res.size()/2; i++){
		swap(res[i], res[res.size()-i-1]);
	}

	return res;
}

long long toInt(vector <long long> v){
	long long res = 0;
	for (long long i = 0; i < v.size(); i++){
		res *= 10;
		res += v[i];
	}

	return res;
}

long long max(long long a, long long b){
	return a > b ? a : b;
}
long long min(long long a, long long b){
	return a < b ? a : b;
}

vector <long long> maximize(vector <long long> n, long long i){
	
	if (i < n.size()){
		long long digit = n[i];
		long long biggest = digit;
		long long bi = i;
		for (long long it = i+1; it < n.size(); it++){
			if (biggest < n[it]){
				biggest = n[it];
				bi = it;
			}
		}

		if (biggest > digit)
			swap(n[i], n[bi]);
		else
			n = maximize(n, i+1);
	}
	return n;
}

vector <long long> minimiza(vector<long long> n, long long i){
	if (i < n.size()){
		long long digit = n[i];
		long long smallest = digit;
		long long si = i;

		for(long long it = i+1; it < n.size(); it++){
			if (smallest >= n[it] && (i != 0 || n[it] != 0)){
				smallest = n[it];
				si = it;
			}
		}

		if (smallest < digit)
			swap(n[i], n[si]);
		else
			n = minimiza(n, i+1);
	}
	return n;
}

int main(){
	long long t;
	scanf("%lld", &t);

	for (long long test = 1; test <= t; test++){
		long long a, b, n;
		a = b = 0;
		scanf("%lld", &n);

		vector<long long> num = toVec(n);

		printf("Case #%lld: %lld %lld\n",test, toInt(minimiza(num, 0)), toInt(maximize(num, 0)));
	}

	return 0;
}