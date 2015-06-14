#include <iostream>
#include <cstring>

using namespace std;

string build(int n, char k){
	string res = "";

	while (n--)
		res = res + k;
	return res;
}

int  main(){

	bool left = true;
	int n, m;

	cin>>n>>m;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			cout<<build(m, '#')<<endl;
		}
		else{
			if (left)
				cout<<build(m-1, '.')<<'#'<<endl;
			else 
				cout<<'#'<<build(m-1, '.')<<endl;
			left = !left;
		}
	}

	return 0;
}