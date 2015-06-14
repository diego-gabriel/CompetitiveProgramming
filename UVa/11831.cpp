#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
vector <string> tab;

string build(int n, char k){
	return n == 0 ? "" : build(n-1, k) + k;
}

struct Dir
{
	int x, y;
	char left, right;
	Dir(){
	}
	Dir(int a, int b, char l, char r){
		x = a;
		y = b;
		left = l;
		right = r;
	}
};

map <char, Dir> state;

int init(){
	state.clear();
	state['N'] = Dir(-1, 0, 'O', 'L');
	state['O'] = Dir(0, -1, 'S', 'N');
	state['S'] = Dir(1, 0, 'L', 'O');
	state['L'] = Dir(0, 1, 'N', 'S');
}

int main(){
	init();
	int row, col, n;
	while (cin>>row>>col>>n){
		if (row == 0 && col == 0 && n == 0)
			break;
		tab.clear();
		int x, y;
		tab.push_back(build(col+2, '#'));
		for (int i = 0; i < row; i++){
			string cad;
			cin>>cad;
			for (int j = 0; j < col; j++){
				if (cad[j] == 'S' || cad[j] == 'N' || cad[j] == 'L' || cad[j] == 'O'){
					x = i+1;
					y = j+1;
				}
			}
			tab.push_back("#"+cad+"#");
		}
		tab.push_back(build(col+2, '#'));
		
		string ins;
		cin>>ins;
		char dir = tab[x][y];
		int res = 0;
		for (int i = 0; i < ins.length(); i++){
			if (ins[i] == 'F'){
				x += state[dir].x;
				y += state[dir].y;
				if (tab[x][y] == '#'){
					x -= state[dir].x;
					y -= state[dir].y;
				}
			}

			if (ins[i] == 'D')
				dir = state[dir].right;
			if (ins[i] == 'E')
				dir = state[dir].left;

			if (tab[x][y] == '*'){
				res++;
				tab[x][y] = '.';
			}
		}
		cout<<res<<endl;

	}


	return 0;
}