#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 210

vector <int> v;
int memo[MAX][MAX][MAX];

void init(){
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				memo[i][j][k] = -1;
	}
}

int min(int a, int b){
	return a < b ? a : b;
}

int solve(int i, int asc, int des){
	
	//cout<<"i: "<<i<<endl;
	if (i == v.size()-1)
		memo[i][asc][des] = 0;

	if (memo[i][asc][des] == -1){
		int notTake, toAsc, toDes;

		notTake = 1 + solve(i+1, asc, des);
		if (v[i] > v[asc])
			toAsc = solve(i+1, i, des);
		else 
			toAsc = 0x7fffffff;

		if (v[i] < v[des])
			toDes = solve(i+1, asc, i);
		else
			toDes = 0x7fffffff;

		memo[i][asc][des] = min(notTake, min(toDes, toAsc));
	}


	return memo[i][asc][des];
}

int main(){

	int n;
	while (cin>>n && n != -1){
		v.clear();
		v.assign(n+2, 0);
		init();
		for (int i = 1; i < n+1; i++)
			cin>>v[i];
		v[0] = 0;
		v[n+1] = 1000000+10;
		cout<<solve(1, 0, n+1)<<endl;

	}

	return 0;
}