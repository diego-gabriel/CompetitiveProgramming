#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Letter
{
	int c;
	int id;
	int m;
	int d;
	int h;
	int s;
	int debt;
	Letter(){};
	void read(int i){
		id = i;
		char k;
		debt = 0;
		scanf("%c%d %d.%d %d:%d\n", &k, &c, &m, &d, &h, &s);
		if (k=='-') c = -c;
	}
};

bool ordID(Letter a, Letter b){
	return a.id < b.id;
}

bool ordIDDate(Letter a, Letter b){
	if (a.m == b.m)
		if (a.d == b.d)
			if (a.h == b.h)
				return a.s < b.s;
			return a.h < b.h;
		return a.d < b.d;
	return a.m < b.m;
}

int main(){
	int n;

	scanf("%d\n", &n);
	Letter l[n];

	for(int i = 0; i < n; i++){
		l[i].read(i);
	}	

	sort(l, l+n, ordIDDate);

	int debt = 0;
	int money = 0;

	for (int i = 0; i < n; i++){
		if (l[i].c < 0){
			//spend
			debt += -min(0, money+l[i].c);
			money = max(0, money+l[i].c);
		}
	}

	return 0;
}