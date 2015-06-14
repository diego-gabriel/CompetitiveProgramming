#include <iostream>

using namespace std;

bool lucky (int a){
	bool res = false;
	while (a && !res){
		res = a % 10 == 8;
		a = a/10;
	}
	return res;
}

int solve (int a){
	int res = 0;
	while (!lucky(a < 0 ? -a : a)){
		a++;
		res++;
	}
	return res;
}

int main(){
	int a;
	cin>>a;

	cout<<solve(a+1)+1<<endl;
	return 0;
}