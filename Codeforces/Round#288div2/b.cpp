#include <iostream>
#include <cstring>

using namespace std;

bool even(char k){
	return (k - '0') % 2 == 0;
}

string best(string n, int l){
	int x, y;
	x = l-1;
	y = 0;
	for (int i = l-1; i >= 0; i--){
		if (n[i] > n[x])
			x = i;
	}



	swap(n[x], n[y]);
	return n;
}

int main(){
	string n;
	cin>>n;
	if (even(n[n.length() -1])){
		cout<<best(n, n.length() -1)<<endl;
	}
	else{

	}
	return 0;
}

/*
65432
5432123456
64324
*/