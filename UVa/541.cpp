#include <iostream>

using namespace std;

int main(){
	int n;
	while (cin>>n && n){
		bool m[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin>>m[i][j];
		int cOddx = 0;
		int cOddy = 0;
		int oddx = 0;
		int oddy = 0;

		for(int i = 0; i < n; i++){
			int c = 0;
			for (int j = 0; j < n; j++)
				c += m[i][j];

			if (c % 2 == 1){
				cOddx++;
				oddx = i;
			}
		}
		for(int j = 0; j < n; j++){
			int c = 0;
			for (int i = 0; i < n; i++)
				c += m[i][j];

			if (c % 2 == 1){
				cOddy++;
				oddy = j;
			}
		}

		if (cOddy == 0 && cOddx == 0)
			cout<<"OK"<<endl;
		else if (cOddy == 1 && cOddx == 1)
			cout<<"Change bit ("<<oddx+1<<","<<oddy+1<<")"<<endl;
		else
			cout<<"Corrupt"<<endl;
	}
	return 0;
}