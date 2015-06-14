#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char mat[110][110];
int dir[8][2];
int cant[9];
void init(){

	dir[0][0] = 0;
	dir[0][1] = 1;
	dir[1][0] = 1;
	dir[1][1] = 0;
	dir[2][0] = -1;
	dir[2][1] = 0;
	dir[3][0] = 0;
	dir[3][1] = -1;

	dir[4][0] = 1;
	dir[4][1] = 1;
	dir[5][0] = -1;
	dir[5][1] = -1;
	dir[6][0] = 1;
	dir[6][1] = -1;
	dir[7][0] = -1;
	dir[7][1] = 1;
}

void dfs(int x, int y, char k){
	mat[x][y] = '0';

	for (int i = 0; i < 8; i++){
		if (mat[x+dir[i][0]][y+dir[i][1]] == k)
			dfs(x+dir[i][0], y+dir[i][1], k);
	}
}

int main(){
	int nTest;
	cin>>nTest;
	init();
	for (int test = 1; test <= nTest; test++){
		int n, m;
		cin>>n>>m;
		memset(mat, '0', sizeof(mat));
		memset(cant, 0, sizeof(cant));
		for (int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>mat[i+1][j+1];
			}
		}

		int res = 0;
		for (int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if (mat[i+1][j+1] != '0'){
					cant[mat[i+1][j+1]-'0'-1]++;
					dfs(i+1, j+1, mat[i+1][j+1]);
					res++;
				}
			}
		}

		printf("Caso #%d: %d\n", test, res);
		cout<<cant[0];
		for (int i = 1; i < 9; i++)
			cout<<" "<<cant[i];
		cout<<endl;

	}
	return 0;
}