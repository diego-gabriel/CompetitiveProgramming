#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	while (n--){
		string cad;
		cin>>cad;
		int res = cad.length();
		int l = cad.length();
		string a = "";
		for (int i = 1; i <= l/2; i++){
			a = a + cad[i-1];
			if (l % i != 0)
				continue;
			string b = "";

			bool ok = true;
			for (int j = 0; j < l; j++){
				if (cad[j] != a[j%i]){
					ok = false;
					break;
				}
			}

			if (ok){
				res = i;
				break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}