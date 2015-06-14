#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

struct Block
{
	int x, y, tam;
	Block(){};
	Block(int a, int b, int c){
		x = min(a, b);
		y = max(a, b);
		tam = c;
	}


};

bool operator > (Block a, Block b){
	return a.x > b.x && a.y > b.y;
}

int main(){

	int n;
	int test = 0;
	while (cin>>n && n){
		test++;
		cout<<"Case "<<test<<": maximum height = ";
		Block blocks[3*n+1];
		int x, y, z;
		for (int i = 0; i < n; i++){
			cin>>x>>y>>z;
			blocks[3*i+0] = Block(x,y,z);
			blocks[3*i+1] = Block(x,z,y);
			blocks[3*i+2] = Block(z,y,x);
		}
		blocks[3*n] = Block(0, 0, 0);

		int dist[3*n][3*n+1];

		for (int i = 0; i < 3*n+1; i++){
			for (int j = 0; j < 3*n+1; j++){
				if (blocks[i] > blocks[j])
					dist[i][j] = blocks[i].tam;
				else
					dist[i][j] = -(0x0fffffff);
			}
		}
		for (int k = 0; k < 3*n+1; k++)
			for (int i = 0; i < 3*n+1; i++)
				for (int j = 0; j < 3*n+1; j++){
					dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
				}
	
		int res = 0;

		for (int i = 0; i < 3*n+1; i++){
			res = max(res, dist[i][3*n]);
		}

		cout<<res<<endl;
		
	}

	return 0;
}