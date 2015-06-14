#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	char tab[n][m];

	int res[m];
	memset(res, 0, sizeof(res));
	for (int i = 0; i < n; i++){

		for (int j = 0; j < m; j++){
			cin>>tab[i][j];

			int vx, vy;
			vx = vy = 0;
			if (tab[i][j] == 'R'){
				vx = 1;
			}else
			if (tab[i][j] == 'L'){
				vx = -1;
			}else
			if (tab[i][j] == 'U'){
				vy = -1;
			}else
			if (tab[i][j] == 'D'){
				vy = 1;
			}
			else continue;

			if (vy != 1){
				int x, y;
				y = i / (1-vy);
				if (y*(1-vy) == i){
					x = j + y*vx;

					if (x >= 0 && x < m && y >= 0 && y < n)
						res[x]++;

				}
			}
		}
	}

	cout<<res[0];
	for(int i = 1; i < m; i++)
		cout<<" "<<res[i];
	cout<<endl;

	return 0;
}