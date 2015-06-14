#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Candy
{
	bool type;
	int m;
	int h;
	Candy(){

	}

	void read(){
		cin>>type>>h>>m;
	}

	bool isCaramel(){
		return type == 0;
	}
};

bool operator < (Candy a, Candy b){
	if (a.h == b.h)
		return a.m > b.m;
	return a.h < b.h;
}

int solve(vector<Candy> drops, bool caramel, int h){
	int res = 0;
	bool used[drops.size()];
	memset(used, false, sizeof(used));

	bool ok = true;

	while (ok){

		Candy candy;
		candy.m = 0;
		candy.h = 0x7fffffff;
		int cIndex;
		ok = false;
		for (int i = 0; i < drops.size(); i++){
			if (!used[i] && drops[i].isCaramel() == caramel){
				if (drops[i].h <= h && drops[i].m > candy.m){
					candy = drops[i];
					cIndex = i;
					ok = true;
				}
			}
		}

		if (ok){
			res++;
			used[cIndex] = true;
			h += candy.m;
			caramel = !caramel;
		}
	}


	return res;
}

int main(){

	int n, h;
	cin>>n>>h;

	vector<Candy> caramel;
	vector<Candy> fruit;

	Candy aCandy;

	for (int i = 0; i < n; i++){
		aCandy.read();
		caramel.push_back(aCandy);
	}

	cout<<max(solve(caramel, true, h), solve(caramel, false, h))<<endl;

	return 0;
}