#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m, tab[1005][1005];

bool s1(int i, int j){
	return tab[i][j] && tab[i+1][j] && tab[i][j+1] && tab[i+1][j+1];
}
bool s2(int i, int j){
	return tab[i][j] && tab[i+1][j] && tab[i][j-1] && tab[i+1][j-1];
}
bool s3(int i, int j){
	return tab[i][j] && tab[i-1][j] && tab[i][j-1] && tab[i-1][j-1];
}
bool s4(int i, int j){
	return tab[i][j] && tab[i-1][j] && tab[i][j+1] && tab[i-1][j+1];
}

int main(){
	int k;
	cin>>n>>m>>k;
	memset(tab, false, sizeof(tab));
	bool loose = false;
	int x, y;
	for (int i = 0; i < k; i++){
		cin>>x>>y;
		tab[x][y] = true;
		if (!loose){
			loose = s1(x, y) || s2(x, y) || s3(x, y) || s4(x, y);
			if (loose)
				cout<<i+1<<endl;
		}
	}

	if (!loose){
		cout<<0<<endl;
	}
	return 0;
}

/*

--*
-**

*/