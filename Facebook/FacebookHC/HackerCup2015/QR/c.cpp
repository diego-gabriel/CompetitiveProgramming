#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char tab[4][104][104];
int dis[4][104][104];

struct Pos
{
	int x, y;
	Pos(){};
	Pos(int a, int b){
		x = a;
		y = b;
	}
};

struct Info
{
	Pos pos;
	int t;
	Info(){};
	Info(Pos a, int b){
		pos = a;
		t = b;
	}
};

char rotate(char k){
	if (k == '^')
		return '>';
	if (k == '>')
		return 'v';
	if (k == 'v')
		return '<';
	if (k == '<')
		return '^';
}

Pos getDir(char k){

	if (k == '^')
		return Pos(-1,0);
	if (k == '>')
		return Pos(0,+1);
	if (k == 'v')
		return Pos(+1,0);
	if (k == '<')
		return Pos(0,-1);	
}

bool isTorret(char k){
	return k == '^' || k == '<' || k == '>' || k == 'v';
}


int min(int a, int b){
	return a < b ? a : b;
}

int min4(int a, int b, int c, int d){
	return min(min(a, b), min(c, d));
}

int main(){
	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		memset(tab, '#', sizeof(tab));
		int n, m;
		cin>>n>>m;
		Pos start, end;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				dis[0][i][j] = 0x0fffffff;
				dis[1][i][j] = 0x0fffffff;
				dis[2][i][j] = 0x0fffffff;
				dis[3][i][j] = 0x0fffffff;
				cin>>tab[0][i][j];
				if (tab[0][i][j] == 'S'){
					start = Pos(i, j);
					tab[0][i][j] = '.';
				}
				if (tab[0][i][j] == 'G'){
					end = Pos(i, j);
					tab[0][i][j] = '.';
				}


				tab[1][i][j] = tab[0][i][j];
				tab[2][i][j] = tab[0][i][j];
				tab[3][i][j] = tab[0][i][j];

				if (isTorret(tab[0][i][j])){
					tab[1][i][j] = rotate(tab[0][i][j]);
					tab[2][i][j] = rotate(tab[1][i][j]);
					tab[3][i][j] = rotate(tab[2][i][j]);
				}
			}
		}

		for (int i = 0; i < 4; i++){
			for (int j = 1; j <= n; j++){
				for (int k = 1; k <= m; k++){
					if (isTorret(tab[i][j][k])){
						Pos p = getDir(tab[i][j][k]);
						tab[i][j][k] = '#';
						int x = j+p.x;
						int y = k+p.y;
						while (tab[i][x][y] == '.'){
							tab[i][x][y] = '#';
							x += p.x;
							y += p.y;

						}
					}
				}
			}
		}

				for (int i = 0; i < 4; i++){
			for (int j = 1; j <= n; j++){
				for (int k = 1; k <= m; k++){
					cout<<tab[i][j][k];
				}
				cout<<endl;

			}
			cout<<endl<<endl;
		}



		queue<Info> cola;
		cola.push(Info(start, 0));
		dis[0][start.x][start.y] = 0;
		tab[0][start.x][start.y] = '#';
		Info inf;

		while(!cola.empty()){
			inf = cola.front();
			cola.pop();
			int dist = inf.t+1;
			int x = inf.pos.x;
			int y = inf.pos.y;

			if (tab[dist%4][x+1][y] == '.'){
				tab[dist%4][x+1][y] = '#';
				dis[dist%4][x+1][y] = dist;
				cola.push(Info(Pos(x+1, y), dist));
			}
			if (tab[dist%4][x-1][y] == '.'){
				tab[dist%4][x-1][y] = '#';
				dis[dist%4][x-1][y] = dist;
				cola.push(Info(Pos(x-1, y), dist));
			}
			if (tab[dist%4][x][y+1] == '.'){
				tab[dist%4][x][y+1] = '#';
				dis[dist%4][x][y+1] = dist;
				cola.push(Info(Pos(x, y+1), dist));
			}
			if (tab[dist%4][x][y-1] == '.'){
				tab[dist%4][x][y-1] = '#';
				dis[dist%4][x][y-1] = dist;
				cola.push(Info(Pos(x, y-1), dist));
			}
		}

		cout<<"Case #"<<test<<": ";
		int res = min4(dis[0][end.x][end.y], dis[1][end.x][end.y], dis[2][end.x][end.y], dis[3][end.x][end.y]);
		if (res == 0x0fffffff)
			cout<<"impossible"<<endl;
		else
			cout<<res<<endl;
	}
	return 0;
}