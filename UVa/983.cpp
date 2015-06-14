#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, m;

	bool fst = true;
	while(cin>>n>>m){
		if (!fst)
			cout<<endl;
		else fst = false;

		long long mat[n][n];
		long long suma[n+1][n+1];
		long long res[n-m+1][n-m+1];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin>>mat[i][j];
		for (int i = 0; i < n+1; i++){
			suma[i][0] = 0;
			suma[0][i] = 0;
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				suma[i+1][j+1] = mat[i][j] + suma[i][j+1] + suma[i+1][j] - suma[i][j];		
			}
		}
		for (int i = 0; i < n-m+1; i++){
			for (int j = 0; j < n-m+1; j++){
				res[i][j] = suma[i+m][j+m] - suma[i][j+m] - suma[i+m][j] + suma[i][j];
			}
		}
		long long sumaR = 0;
		for (int i = 0; i < n-m+1; i++)
			for (int j = 0; j < n-m+1; j++){
				cout<<res[i][j]<<endl;
				sumaR += res[i][j];
			}
		cout<<sumaR<<endl;

	}
	return 0;
}