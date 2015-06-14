#include <map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int abs(int a){
	return a > 0 ? a : -a;
}

struct Pos
{
	int x, y;
	Pos(){};
	Pos(int a,int b){
		x = a;
		y = b;
	}

	int dist(Pos a){
		return  abs(x-a.x) + abs(y-a.y);		
	}
};


int min(int a, int b){
	return a < b ? a : b;
}

struct Tecla
{
	vector<Pos> keys;

	Tecla(){};
	void add(Pos a){
		keys.push_back(a);
	}

	Pos closest(Pos a){
		Pos r;
		int res = 0x0fffffff;
		int d;
		int n = keys.size();
		for (int i = 0; i < n; i++){

			d = a.dist(keys[i]);
			if (d < res){
				r = keys[i];
				res = d;
			}
		}

		return r;
	}
};


map <char, Tecla> teclas;
int memo[10100][55][55];
bool solved[10100][55][55];

int main(){

	int n, m;
	cin>>n>>m;
	char k;



	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin>>k;
			teclas[k].add(Pos(i, j));
		}
	}

	string cad;
	cin>>cad;
	cad = cad + "*";
	int res = cad.length()-1;
	Pos last = Pos(0, 0);
	Pos ot;
	for (int i = 0, l = cad.length(); i < l; i++){
		ot = teclas[cad[i]].closest(last);
		res += ot.dist(last);
		cout<<"added: "<<ot.dist(last)<<endl;
		last = ot;
	}

	cout<<res<<endl;
	return 0;
}