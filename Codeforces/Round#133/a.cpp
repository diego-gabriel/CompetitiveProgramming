#include <iostream>

using namespace std;

int main(){

	int a, b, c;

	cin>>a>>b>>c;

	int res = 0;
	int tiles = a; 
	if (b > c)
		swap(c, b);

	for(int i = 1; i <= b; i++){
		res += tiles;
		tiles++;
	}
	int max = tiles-1;
	tiles = a;

	for(int i = 1; i < c; i++){
		res += tiles;
		tiles = tiles + 1 < max ? tiles+1 : max;
	}
	cout<<res<<endl;

	return 0;
}