#include <iostream>
#include <cstring>

using namespace std;

bool marked[60][60];
char tab[60][60];
int t[60][60];
int d[4][2];

bool check (int x, int y, char k, int step){
	bool res= false;

	marked[x][y] = true;
	if (tab[x][y] == k){
		t[x][y] = step;

		for (int i = 0; i < 4 && !res; i++){
			int dx = x + d[i][0];
			int dy = y + d[i][1];

			if (tab[dx][dy] == k && marked[dx][dy] && (t[x][y] - t[dx][dy] >= 3))
				res = true;
			else{
				if (tab[dx][dy] == k && !marked[dx][dy])
					res = check(dx, dy, k, step+1);
			}
		}

	}	


	return res;
}

int main(){

	memset(marked, false, sizeof(marked));
	memset(tab, '.', sizeof(tab));
	memset(t, 0, sizeof(t));

	d[0][0] = 0;
	d[0][1] = 1;
	d[1][0] = 0;
	d[1][1] = -1;
	d[2][0] = 1;
	d[2][1] = 0;
	d[3][0] = -1;
	d[3][1] = 0;

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin>>tab[i][j];

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (marked[i][j])
				continue;
			if (check(i, j, tab[i][j], 0)){
				cout<<"Yes"<<endl;
				return 0;
			}

		}

	cout<<"No"<<endl;
	return 0;
}