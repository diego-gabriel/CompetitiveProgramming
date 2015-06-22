#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char tab[1510][1510];
bool vis[1510][1510];

int n, m;

bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int x, int y){
	queue<pair<int, int> > cola;
	cola.push(make_pair(x, y));
	pair<int, int> o;

	while (!cola.empty()){
		o = cola.front();
		cola.pop();
		
		x = o.first;
		y = o.second;

		if (valid(x+1, y) && tab[x+1][y] == '.'){
			tab[x+1][y] = 'S';
			cola.push(make_pair(x+1, y));
		}
		if (valid(x-1, y) && tab[x-1][y] == '.'){
			tab[x-1][y] = 'S';
			cola.push(make_pair(x-1, y));
		}
		if (valid(x, y+1) && tab[x][y+1] == '.'){
			tab[x][y+1] = 'S';
			cola.push(make_pair(x, y+1));
		}
		if (valid(x, y-1) && tab[x][y-1] == '.'){
			tab[x][y-1] = 'S';
			cola.push(make_pair(x, y-1));
		}

	}

}

int main(){
	cin>>n>>m;

	int x,y;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>tab[i][j];
			if(tab[i][j] == 'S'){
				x = i;
				y = j;
			}
		}
	}

	bfs(x, y);
	
	bool okh = false;
	bool okv = false;


	for (int i = 0; i < n && !okh; i++){
		bool flag = false;
		okh = okh || (tab[i][0] == 'S' && tab[i][m-1] == 'S');
	}


	for (int j = 0; j < m && !okv; j++){
		okv = okv || (tab[0][j] == 'S' && tab[n-1][j] == 'S');
	}

	if (okh || okv)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}