#include <bits/stdc++.h>

using namespace std;
struct Point
{
	int x, y, e;
	Point(){
		x = y = e = 0;
	}
	void read(){
		cin>>x>>y>>e;
	}
};

map <int, Point> points;
map <int, map <int, int> > memo;

int on(int n){
	int res = 0;
	while (n--){
		res = res << 1;
		res = res | 1;
	}
	return res;
}

int solve(int c, int p, int x, int y){
	int res = abs(x) + abs(y) + c;
	if (!memo[c][p]){

		if (p){
			int cp = p;
			int bit;
			while (cp){
				bit = cp & (-cp);
//				cout<<"bit: "<<bit<<endl;
				cp -= bit;
				int dist = abs(points[bit].x - x) + abs(points[bit].y - y); 
				if (dist <= c){
					res = max(res, solve(c-dist+points[bit].e, p-bit, points[bit].x, points[bit].y));
				}
			}
		}

		memo[c][p] = res;
	}
//	cout<<"res: "<<memo[c][p]<<endl;
	return memo[c][p];
}

int main(){

	int nT;
	cin>>nT;
	for (int test = 0; test < nT; test++){
		int c, p;
		cin>>c>>p;
		memo.clear();
		points.clear();
		for (int i = 1; i < 1<<p; i = i<<1){
		//	cout<<"i: "<<i<<endl;
			points[i].read();
		}
		cout<<"Caso #"<<test+1<<": ";
		cout<<solve(c, on(p), 0, 0)<<endl;



	}

	return 0;
}