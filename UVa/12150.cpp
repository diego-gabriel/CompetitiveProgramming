#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int n;
	while (cin>>n && n){
		int p, g;
		int pos[n+1];
		memset(pos, 0, sizeof(pos));
		bool ok = true;
		for (int i = 1; i <= n; i++){
			cin>>p>>g;

			if (ok){
				int npos = i + g;

				if (npos > n || npos < 1 || pos[npos] != 0)
					ok = false;
				else{
					pos[npos] = p;
				}

			}
		}

		if (!ok)
			cout<<-1<<endl;
		else {
			cout<<pos[1];
			for (int i = 2; i <= n; i++)
				cout<<" "<<pos[i];
			cout<<endl;
		}
	}
	return 0;
}