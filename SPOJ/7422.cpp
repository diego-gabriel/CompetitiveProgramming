#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Pos
{
	int x, y;
	bool z;
	Pos(){};
	Pos(int a, int b, bool c){
		x = a;
		y = b;
		z = c;
	}

	void print(){
		cout<<"x: "<<x<<" | y: "<<y<<" | z: "<<((int)z)<<" ("<<z<<")"<<endl;
	}
};

int main(){
	int w, h;
	while (cin>>h>>w){
		if (h == -1 && w == -1)
			break;

		char tab[h+2][w+2][2];
		int dis[h+2][w+2][2];
		int best = 0x7fffffff;
		char k;
		memset(tab, 'E', sizeof(tab));

		Pos start;
		for (int i = 1; i < h+1; i++){
			for(int j = 1; j < w+1; j++){
				cin>>k;
				if (k == 'H'){
					start = Pos(i, j, false);
					k = '.';
				}

				tab[i][j][0] = tab[i][j][1] = k;
			}
		}

		queue<Pos> cola;
		cola.push(start);
		dis[start.x][start.y][start.z] = 0;
		tab[start.x][start.y][start.z] = 'W';
		int x, y;
		bool z;
		Pos origen, destino;

		int d[4][2];

		d[0][0] = 1;
		d[0][1] = 0;

		d[1][0] = 0;
		d[1][1] = 1;

		d[2][0] = -1;
		d[2][1] = 0;

		d[3][0] = 0;
		d[3][1] = -1;

		while (!cola.empty()){
			origen = cola.front();
			cola.pop();

			x = origen.x;
			y = origen.y;
			z = origen.z;



			for (int i = 0; i < 4; i++){
				if (tab[x+d[i][0]][y+d[i][1]][z] == '.' || (tab[x+d[i][0]][y+d[i][1]][z] == 'D' && z)){
					tab[x+d[i][0]][y+d[i][1]][z] = 'W';
					dis[x+d[i][0]][y+d[i][1]][z] = dis[x][y][z] + 1;
					cola.push(Pos(x+d[i][0], y+d[i][1], z));
					//cout<<"pushed"<<endl;
					//cola.front().print();
				}
				if (tab[x+d[i][0]][y+d[i][1]][z] == 'O' && tab[x+d[i][0]][y+d[i][1]][1] != 'W'){
					tab[x+d[i][0]][y+d[i][1]][1] = 'W';
					dis[x+d[i][0]][y+d[i][1]][1] = dis[x][y][z] + 1;
					cola.push(Pos(x+d[i][0], y+d[i][1], 1));	

					//cout<<"pushed"<<endl;
					//cola.front().print();
				}
				if (tab[x+d[i][0]][y+d[i][1]][z] == 'C' && tab[x+d[i][0]][y+d[i][1]][0] != 'W'){
					tab[x+d[i][0]][y+d[i][1]][0] = 'W';
					dis[x+d[i][0]][y+d[i][1]][0] = dis[x][y][z] + 1;
					cola.push(Pos(x+d[i][0], y+d[i][1], 0));	
					//cout<<"pushed"<<endl;
					//cola.front().print();
				}
				if (tab[x+d[i][0]][y+d[i][1]][z] == 'E'){
					best = min(best, dis[x][y][z] + 1);
				}
				
			}
		}

		cout<<(best == 0x7fffffff ? -1 : best)<<endl;

	}
	return 0;
}