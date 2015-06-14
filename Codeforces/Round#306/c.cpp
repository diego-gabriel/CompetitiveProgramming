#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool check(int i, string &n){
	char k;
	if (i == 0){
		for (int j = n.length()-1; j >= 0; j--){
			if (n[j] == '0')
				return true;
		}
		return false;
	} else {
		for (int j = n.length()-1; j >= 0 && i; j--){
			k = n[j];
			if (k-'0' == (i%10)){
				i /= 10;
			}
		}
	}

	return i == 0;
}

int main(){
	string n;
	cin>>n;

	bool ok = false;

	for (int i = 0; i < 1000; i += 8){
		if (check(i, n)){
			cout<<"YES"<<endl<<i<<endl;
			ok = true;
			break;
		}
	}


	if (!ok)
		cout<<"NO"<<endl;

	return 0;
}