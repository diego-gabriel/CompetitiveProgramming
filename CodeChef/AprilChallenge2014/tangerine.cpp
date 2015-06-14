#include <iostream>
#include <algorithm>

using namespace std;

struct Segment
{
	int r, l;
	Segment(){r = l = 0;}
	void read(){
		cin>>l>>r;
	}
};

bool orden(Segment a, Segment b){
	return a.l < b.l;
}
bool isIn(Segment a, Segment b){
	bool res;
	if (b.l <= b.r && a.l <= a.r){
		res = a.r >= b.l && a.l >= b.l && a.r <= b.r && a.l <= b.r;
	}
	else
	{
		if (a.l >= b.l){
			if (a.r <= b.r && a.l != b.r)
				res = true;
			else
				if (a.r >= a.l)
					res = true;
				else res = false;
		} else
		res = false;
	}
	return res;
}
int main()
{
	int test;
	cin>>test;

	while (test--){
		int n, k, p;
		cin>>n>>k>>p;
		Segment chef[k], boy[p];

		for (int i = 0; i < k; i++)
			chef[i].read();
		for (int i = 0; i < p; i++)
			boy[i].read();

		sort(chef, chef + k, orden);
		sort(boy, boy + p, orden);
		bool solve = true;

		for (int i = 0; i < k && solve; i++){

			bool in = false;
			for (int j = 0; j < p && !in; j++){
				in = isIn(chef[i], boy[j]);
				if (in)
					cout<<chef[i].l<<" - "<<chef[i].r<<" is in: "<<boy[j].l<<" - "<<boy[j].r<<endl;
			}
			solve = in;
		}

		if (solve) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}