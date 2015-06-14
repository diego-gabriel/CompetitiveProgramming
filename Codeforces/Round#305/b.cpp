#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

struct Info
{
	int v;
	Info(){};
	Info(int a){
		v = a;
	}
};

bool operator < (Info a, Info b){
	return a.v > b.v;
}

int mat[505][505];
int n, m, q;

Info countRow(int i){
	int res = 0;
	int best = 0;
	for (int j = 0; j < m; j++){
		if (mat[i][j] == 1){
			res++;
		}
		else{
			best = best > res ? best : res;
			res = 0;
		}
	}
	best = best > res ? best : res;

	return Info(best);
}

int main(){

	cin>>n>>m>>q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin>>mat[i][j];
	multiset<Info> aSet;
	multiset<Info> :: iterator it;

	for (int i = 0; i < n; i++){
		aSet.insert(countRow(i));
	}
//	cout<<"u"<<endl;
	int x, y;
	Info aInfo;

	for (int i = 0; i < q; i++){
		cin>>x>>y;
		aInfo = countRow(x-1);
		x--;
		y--;

		if (x >= 500 || y>= 500)
			cout<<"ups"<<endl;
		mat[x][y] = mat[x][y] == 1 ? 0 : 1;
		//cout<<"---"<<aInfo.v<<endl;
		//cout<<aSet.size()<<endl;

		aSet.erase(aSet.find(aInfo));
		//cout<<aSet.size()<<endl;
		//cout<<"-----"<<endl;
		aInfo = countRow(x);
		aSet.insert(aInfo);

		it = aSet.begin();
		aInfo = *it;

		cout<<aInfo.v<<endl;
	}
	return 0;
}