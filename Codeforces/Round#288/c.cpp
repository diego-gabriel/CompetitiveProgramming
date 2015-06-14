#include <iostream>
#include <cstring>

using namespace std;

int h, a, d;
int memo[205][205][205];
int hp_y, atk_y, def_y;
int hp_m, atk_m, def_m;

bool win(int hp, int atk, int def){
	int d1 = max(0, atk_m - def);
	int d2 = max(0, atk - def_m);

	return hp*d2 > hp_m*d1;
}

int main(){
	int res = 0x7fffffff;

	cin>>hp_y>>atk_y>>def_y;
	cin>>hp_m>>atk_m>>def_m;
	cin>>h>>a>>d;

	for (int i = hp_y; i < 201; i++)
		for (int j = atk_y; j < 201; j++)
			for (int k = def_y; k < 201; k++){
				if (win(i, j, k)){
					memo[i][j][k] = max(0, i-hp_y)*h + max(0, j-atk_y)*a + max(0, k-def_y)*d;
				}
				else
					memo[i][j][k] = 0x7fffffff;
				res = min(res, memo[i][j][k]);

			}


	cout<<res<<endl;

	return 0;
}