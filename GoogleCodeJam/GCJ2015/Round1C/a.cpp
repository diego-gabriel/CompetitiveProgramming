#include <iostream>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++){
		int r, c, w;
		cin>>r>>c>>w;

		int res = c/w;
		res *= r;

		res += w-1;
		if (c%w != 0){
			res++;
		}

		cout<<"Case #"<<test<<": "<<res<<endl;
	}
	return 0;
}