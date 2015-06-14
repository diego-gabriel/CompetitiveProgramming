#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int nTest;
	cin>>nTest;
	int test = 0;
	while (nTest--){
		test++;
		int n;
		cin>>n;
		string coin[n];

		for (int i = 0; i < n; i++){
			cin>>coin[i];
		}

		string curr = coin[0];

		for (int i = 1; i < n; i++){
			if (curr == coin[i])
				curr = "hhb";
			else
				curr = "lxh";
		}

		cout<<curr<<endl;
	}
	return 0;
}