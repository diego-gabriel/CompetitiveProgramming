#include <iostream>
#include <cstring>

using namespace std;

int tab[100][100];

void setTable(){
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++)
			tab[i][j] = 0;
	}
}

int main(){
	int nTest;
	cin>>nTest;
	for (int test = 1; test <= nTest; test++){
		int r, c, m;
		cin>>r>>c>>m;
		setTable();
		int row, col;
		row = r, 
		col = c;
		while (m){
			fillMines(r, c, min(m, r+c-1));
			m -= min(m, r+c-1);
			r = min(r-1, 3);
			c--;
		}
	}
	return 0;
}