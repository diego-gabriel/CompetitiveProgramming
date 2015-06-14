#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string a, b;
	while (cin>>a>>b){
		a = " " + a;
		b = " " + b;
		int dist[a.length()][b.length()];
		memset(dist, 0, sizeof(dist));

		for (int i = 1; i < a.length(); i++){
			for (int j = 1; j < b.length(); j++){
				if (a[i] == b[j])
					dist[i][j] = dist[i-1][j-1]+1;
				else
					dist[i][j] = max(dist[i-1][j], dist[i][j-1]);
			}
		}

		int i = a.length()-1;
		int j = b.length()-1;
		string res = "";
		while (i > 0 && j > 0){
			if (a[i] == b[j]){
				res = a[i] + res;
				i--;
				j--;
			}
			else{
				if (dist[i-1][j] == dist[i][j])
					i--;
				else 
					j--;
			}
		}

		cout<<res<<endl;
	}
	return 0;
}