#include <iostream>
#include <cstring>

using namespace std;

int w;

bool solve(int m){
	
	bool res;

	if (m == 0)
		res = true;
	else {
		if (m % w == 1){
			res = solve((m-1)/w);
		} else if (m % w == w-1){
			res = solve((m+1)/w);
		} else if (m % w == 0){
			res= solve(m/w);
		}
		else
			res = false;
	}

	return res;
}

int main(){
	int m;
	cin>>w>>m;
	bool ok = false;





	if (solve(m))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}