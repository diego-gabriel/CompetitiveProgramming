#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

long long n;

long long min(long long a, long long b){
	return a < b ? a : b;
}

long long max(long long a, long long b){
	return a > b ? a : b;
}

long long dist(long long &a, long long &b){
	return min(max(a, b) - min(a, b), n - max(a, b) + min(a, b));
}

struct Arc
{
	int red;
	int blue;

	Arc(){};
	Arc(int a, char b){
		res = a;
		blue = b;
	}

	int distance(){
		return dist(red, blue);
	}
};


bool operator < (Arc a, Arc b){
	return a.distance() < b.distance();
}

int main(){
	long long t, r, b;
	cin>>t;
	while(t--){
		cin>>n>>r>>b;
		long long res = 0;

		set<int> reds;
		set<int> :: iterator it;
		char p;
		for (int i = 0; i < r; i++){
			cin>>p;
			reds.insert(p);
		}

		for (int i = 0; i < b; i++){
			cin>>p;
			reds.insert(p);
			it = reds.find(p);
		}



		cout<<res;
		if (t)
			cout<<endl;
	}
	return 0;
}