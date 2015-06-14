#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int p[300][2];
int main(){

	p['a'][0] = 1;
	p['a'][1] = 1;
	p['b'][0] = 1;
	p['b'][1] = 2;
	p['c'][0] = 1;
	p['c'][1] = 3;
	p['d'][0] = 2;
	p['d'][1] = 1;
	p['e'][0] = 2;
	p['e'][1] = 2;
	p['f'][0] = 2;
	p['f'][1] = 3;
	p['g'][0] = 3;
	p['g'][1] = 1;
	p['h'][0] = 3;
	p['h'][1] = 2;
	p['i'][0] = 3;
	p['i'][1] = 3;

	string line;
	int test = 0;
	while(getline(cin, line)){
		test++;
		int m[5][5];
		memset(m, 0, sizeof(m));
		int dx, dy;
		char k;
		for (int i = line.length()-1; i >= 0; i--){
			k = line[i];
			dx = p[k][0];
			dy = p[k][1];

			m[dx][dy]++;
			m[dx][dy] %= 10;
			m[dx+1][dy]++;
			m[dx+1][dy] %= 10;
			m[dx-1][dy]++;
			m[dx-1][dy] %= 10;
			m[dx][dy+1]++;
			m[dx][dy+1] %= 10;
			m[dx][dy-1]++;
			m[dx][dy-1] %= 10;
		}

		cout<<"Case #"<<test<<":"<<endl;
		for (int i = 1; i <= 3; i++){
			cout<<m[i][1];
			for (int j = 2; j <= 3; j++)
				cout<<" "<<m[i][j];
			cout<<endl;
		}
	}


	return 0;
}