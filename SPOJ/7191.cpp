#include <iostream>
#include <cstring>

using namespace std;

int tot;

string rep(int n, string cad){
	string res = "";
	for (int i = 0; i < n; i++){
		res = res + cad;
	}
	return res;
}

void open(int i){
	string res = "";
	int n = tot;
	res = rep(1+2*(n-i), " ") + rep(i-1, "_/ \\") + "_";
	cout<<res<<endl;
}
void closeStr(int i, int n){
	string res = "";
	res = rep(i*2-1, " ") + rep(n, " \\_/");
	cout<<res<<endl;

}
void midO(int i){
	string res = "";
	res = rep(i, "/ \\_") + "/ \\";
	cout<<res<<endl;
}
void midC(int i){
	string res = "";
	res = rep(i, "\\_/ ") + "\\_/";
	cout<<res<<endl;
}


int main(){
	while (cin>>tot && tot != -1){
		for (int i = 1; i <= tot; i++){
			open(i);
		}
		for (int i = 1; i <= tot; i++){
			midO(tot-1);
			midC(tot-1);
		}
		for (int i = 1; i < tot; i++){
			closeStr(i, tot-i);
		}
		cout<<"***"<<endl;

	}
	return 0;
}