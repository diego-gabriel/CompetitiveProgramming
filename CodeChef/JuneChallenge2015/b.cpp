#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Polygon
{
	int id;
	int lx;

	Polygon(){
		lx = 0x7fffffff;
	};

	void add(int x){
		lx = lx < x ? lx : x;
	}
};


bool ord (Polygon a, Polygon b){
	return a.lx < b.lx;
}

int main(){
	int test;

	cin>>test;

	while (test--){
		int n, m, x, y;

		cin>>n;
		Polygon poly[n];
		int memo[n];
		for (int i = 0; i < n; i++){
			poly[i].id = i;
			cin>>m;
			while (m--){
				cin>>x>>y;
				poly[i].add(x);
			}
		}

		sort(poly, poly+n, ord);

		for (int i = 0; i < n; i++){
			memo[poly[i].id] = n-i-1;
		}

		cout<<memo[0];
		for (int i = 1; i < n; i++)
			cout<<" "<<memo[i];

		cout<<endl;



	}
	return 0;
}