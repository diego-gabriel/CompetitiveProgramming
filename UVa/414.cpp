#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		cin.ignore();
		int t[n];
		int m = 0;
		for (int i = 0; i < n; i++){
			string cad;
			getline(cin, cad);
			int s = 0;
			for(int k = 0; k < 25; k++){
				if (cad[k] == 'X')
					s++;
			}

			t[i] = s;
			m = s > m ? s : m;
		}

		int res = 0;
		for (int i = 0; i < n; i++)
			res += (m - t[i]);
		cout<<res<<endl;
	}
	return 0;
}