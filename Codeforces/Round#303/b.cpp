#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string a, b;
	cin>>a>>b;
	bool ok = true;
	bool toa = true;
	string res = "";

	for (int i = 0; i < a.length(); i++){
		if (a[i] != b[i]){
			if (toa)
				res = res + a[i];
			else
				res = res + b[i];
			toa = !toa;
		}
		else
			res = res + a[i];
	}


	if (toa)
		cout<<res<<endl;
	else
		cout<<"impossible"<<endl;

}