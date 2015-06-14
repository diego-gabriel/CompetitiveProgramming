#include <iostream>
#include <cstring>

using namespace std;

int solve(string cad){
	int res = 0;
	int count = 0;

	for (int i = 0; i < cad.length(); i++){
		if (cad[i] == 'X')
			count = 0;
		else{
			count++;
			res += count;
		}
	}

	return res;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		string cad;
		cin>>cad;
		cout<<solve(cad)<<endl;
	}
	return 0;
}