#include <iostream>
#include <cstring>
using namespace std;

bool tab[200][200];
int n, m;
bool solve(int x, int y, bool up){
	bool res = tab[x][y];
//	cout<<"("<<x<<", "<<y<<") ";
	if (res && y < m){

		if (!up && x == n){
			up = true;
		}
		else
		if (up && x == 1)
			up = false;

		if (up)
			res = solve(x-1, y+1, up);
		else
			res = solve(x+1, y+1, up);
	}

	return res;
}

int main(){
	while (cin>>n>>m){
		memset(tab, false, sizeof(tab));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cin>>tab[i+1][j+1];
		}

		if (solve(1, 1, false))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}