#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct Posicion
{
	int x, y;
	Posicion(){}
	Posicion(int a, int b){
		x = a;
		y = b;
	}
};

int bfs(vector <string> tab, Posicion origen, char target){
	int dist[15][15];


	queue<Posicion> cola;
	cola.push(origen);
	dist[origen.x][origen.y] = 0;
	tab[origen.x][origen.y] = 'x';
	int x, y;
	Posicion destino, res;
	while (!cola.empty()){
		origen = cola.front();
		cola.pop();

		x = origen.x;
		y = origen.y;

		if (tab[x+1][y] != 'x'){
			cola.push(Posicion(x+1, y));
			if (tab[x+1][y] == target)
				res = Posicion(x+1, y);
			tab[x+1][y] = 'x';
			dist[x+1][y] = dist[x][y]+1;

		}
		
		if (tab[x-1][y] != 'x'){
			cola.push(Posicion(x-1, y));
			if (tab[x-1][y] == target)
				res = Posicion(x-1, y);
			tab[x-1][y] = 'x';
			dist[x-1][y] = dist[x][y]+1;

		}
	
		if (tab[x][y+1] != 'x'){
			cola.push(Posicion(x, y+1));
			if (tab[x][y+1] == target)
				res = Posicion(x, y+1);
			tab[x][y+1] = 'x';
			dist[x][y+1] = dist[x][y]+1;

		}
		
		if (tab[x][y-1] != 'x'){
			cola.push(Posicion(x, y-1));
			if (tab[x][y-1] == target)
				res = Posicion(x, y-1);
			tab[x][y-1] = 'x';
			dist[x][y-1] = dist[x][y]+1;

		}
		
	}
		
	return dist[res.x][res.y];
}

int main(){
	vector <string> tab1, tab2;
	string cad;
	int xe, ye, x, y, yk, xk;
	tab1.push_back("xxxxxxxxxxx");
	tab2.push_back("xxxxxxxxxxx");
	for (int i = 0; i < 10; i++){
		cin>>cad;
		tab1.push_back("x"+cad+"x");
		tab2.push_back("x"+cad+"x");
		for (int j = 0; j < 10; j++){
			if (cad[j] == 'e'){
				xe = i+1;
				ye = j+1;
			}
			if (cad[j] == 'm'){
				x = i+1;
				y = j+1;
			}
			if (cad[j] == 'k'){
				xk = i+1;
				yk = j+1;
			}
		}
	}

	tab1.push_back("xxxxxxxxxxx");
	tab2.push_back("xxxxxxxxxxx");

	int res = 0;
	res = bfs(tab1, Posicion(x, y), 'k') + bfs(tab2, Posicion(xk, yk), 'e');
	cout<<res<<endl;
	return 0;
}