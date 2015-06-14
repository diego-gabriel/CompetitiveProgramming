#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	int x1, x2, y1, y2;
	cin>>x1>>y1>>x2>>y2;

	if (x1 == x2){
		int d = y1-y2;
		printf("%d %d %d %d\n", x1+d, y1, x2+d, y2);
	}
	else
	if (x1-y1 == x2-y2){
		printf("%d %d %d %d\n", x1, y2, x2, y1);	
	}
	else
	if (y1 == y2){
		int d = x1-x2;
		printf("%d %d %d %d\n", x1, y1+d, x2, y2+d);
	}
	else
	if (x1-x2 == y2-y1){
		printf("%d %d %d %d\n", x1, y2, x2, y1);
	}
	else
		printf("-1\n");

	return 0;
}