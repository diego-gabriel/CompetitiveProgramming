#include <iostream>
#include <cstring>

using namespace std;

int matrix[12][12];
int n;


void row(int a, int b){
	for (int y = 1; y <= n; y++){
		swap(matrix[a][y], matrix[b][y]);
	}
}
void col(int a, int b){
	for (int x = 1; x <= n; x++){
		swap(matrix[x][a], matrix[x][b]);
	}
}

void inc(){
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			matrix[x][y]++;
			matrix[x][y] %= 10;
		}
	}
}

void dec(){
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			matrix[x][y] += 10;
			matrix[x][y]--;
			matrix[x][y] %= 10;
		}
	}
}
void tra(){
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= x; y++){
			swap(matrix[x][y], matrix[y][x]);
		}
	}
}



int main(){
	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		if (test > 1)
			cout<<endl;

		cin>>n;
		char k;
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				cin>>k;
				matrix[i][j] = k -'0';
			}

		int m;
		cin>>m;
		string op;
		int a, b;
		for (int i = 0; i < m; i++){
			cin>>op;

			if (op[0] == 'r'){
				cin>>a>>b;
				row(a, b);
			}
			if (op[0] =='c'){
				cin>>a>>b;
				col(a, b);
			}
			if (op[0] == 'i'){
				inc();
			}
			if (op[0] == 't'){
				tra();
			}
			if (op[0] == 'd'){
				dec();
			}
		}
		cout<<"Case #"<<test<<endl;
		for(int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cout<<matrix[i][j];
			}
			cout<<endl;
		}
	}
}