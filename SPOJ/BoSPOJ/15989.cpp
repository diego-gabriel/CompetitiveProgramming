#include <iostream>

using namespace std;

int main(){
	int h, m;
	while (cin>>h>>m){
		h = h % 12;

		cout<<(360/12) * h<<" "<<(360/60)*m<<endl;
	}
	return 0;
}