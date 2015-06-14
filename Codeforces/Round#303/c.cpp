#include <iostream>

using namespace std;


struct Tree
{
	long long pos;
	long long h;

	Tree(){};
	Tree(long long a, long long b){
		pos = a;
		h = b;
	}

	void read(){
		cin>>pos>>h;
	}
};

int main(){

	long long n;
	cin>>n;

	Tree trees[n+5];

	for (long long i = 0; i < n; i++){
		trees[i].read();
	}
	trees[n] = Tree(5000000000, 0);

	long long last = -5000000000;
	long long res = 0;

	for (long long i = 0; i < n; i++){
		//fall left
		if (trees[i].pos - trees[i].h > last){
			res++;
			last = trees[i].pos;
		}
		else
			//fall right
		if (trees[i].pos + trees[i].h < trees[i+1].pos){
			last = trees[i].pos+trees[i].h;
			res++;
		}
		else
			last = trees[i].pos;
	}
	cout<<res<<endl;
	return 0;
}