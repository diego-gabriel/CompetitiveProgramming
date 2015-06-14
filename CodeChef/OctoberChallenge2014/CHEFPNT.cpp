#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool tab[110][110];

struct Mov
{
	int x, y, d;
	Mov(int a, int b, int c){
		x = a;
		y = b;
		d = c;
	}

	void print(){
		printf("%d %d %d\n", x, y, d);
	}
};

void fill(int x, int y, int dx, int dy){
	int i, j;
	i = x;
	j = y;
	while (tab[x][y]){
		tab[x][y] = false;
		x+=dx;
		y+=dy;
	}
	tab[i][j] = true;
}

Mov fill(int x, int y, int d){

	if (d == 1){
		fill (x, y, -1, 0);
		fill (x, y, +1, 0);
	}
	else{
		fill(x, y, 0, +1);
		fill(x, y, 0, -1);
	}

	tab[x][y] = false;
	return Mov(x, y, d);
}

int count(int x, int y, int dx, int dy){
	int res = 0;
	while (tab[x][y]){
		x+=dx;
		y+=dy;
		res++;
	}
	return res;
}

int bestDir(int x, int y){
	int up, lef;
	up = count(x, y, 0, +1) - 1 + count(x, y, 0, -1);
	lef = count(x, y, 1, 0) - 1 + count(x, y, -1, 0);

	return up > lef ? 0 : 1;
}

int main(){
	memset(tab, false, sizeof(tab));

	int n, m, k;
	cin>>n>>m>>k;

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			tab[i][j] = true;
	int x, y;
	for (int i = 0; i < k; i++){
		cin>>x>>y;
		tab[x][y] = false;
	}

	vector <Mov>res;

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (tab[i][j])
				res.push_back(fill(i, j, bestDir(i, j)));
		}
		
	cout<<res.size()<<endl;
	for (int i = 0; i < res.size(); i++)
		res[i].print();

}
