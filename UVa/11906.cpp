#include <iostream>
#include <cstring>

using namespace std;

int grid[105][105];
bool vis[105][105];
bool check[105][105];
int r, c, m, n;
int d[8][2];

void setD(){
	d[0][0] = m;
	d[0][1] = n;

	d[1][0] = m;
	d[1][1] = -n;

	d[2][0] = -m;
	d[2][1] = n;

	d[3][0] = -m;
	d[3][1] = -n;

	d[4][0] = n;
	d[4][1] = m;

	d[5][0] = n;
	d[5][1] = -m;

	d[6][0] = -n;
	d[6][1] = m;

	d[7][0] = -n;
	d[7][1] = -m;
}

bool isValid(int x, int y){
	return x >= 0 && y >= 0 && x < r && y < c;
}

void dfs(int x, int y){
	vis[x][y] = true;

	for (int i = 0; i < 8; i++){
		int dx = x+d[i][0];
		int dy = y+d[i][1];
		if (isValid(dx, dy) && !vis[dx][dy])
			dfs(dx, dy);
	}
}

int countOn(int x, int y){
	int res = 0;	
	memset(check, false, sizeof(check));

	for (int i = 0; i < 8; i++){
		int dx = x+d[i][0];
		int dy = y+d[i][1];
		if (isValid(dx, dy) && grid[dx][dy] != -1 && vis[dx][dy] && !check[dx][dy]){
			res++;
			check[dx][dy] = true;
		}
	}

	return res;
}

int main(){
	int nTest;
	cin>>nTest;
	for (int test = 1; test <= nTest; test++){
		cin>>r>>c>>m>>n;

		int w;
		cin>>w;
		memset(grid, 0, sizeof(grid));
		memset(vis, false, sizeof(vis));
		setD();
		int x, y;
		for (int i = 0; i < w; i++){
			cin>>x>>y;
			grid[x][y] = -1;
			vis[x][y] = true;
		}

		dfs(0, 0);

		int count[2];
		count[0] = count[1] = 0;

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if(vis[i][j] && grid[i][j] != -1)
					count[countOn(i, j)%2]++;
			}
		}

		cout<<"Case "<<test<<": "<<count[0]<<" "<<count[1]<<endl;

	}
}