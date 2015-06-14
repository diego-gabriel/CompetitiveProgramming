#include <iostream>
#include <vector>

using namespace std;

#define INF 0x02ffffff

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	int n;
	while (cin>>n && n){
		vector <char> cad(n, '.');
		vector <int> dis(n, 0);
		int dist = INF;
		char k;
		for (int i = 0; i < n; i++){
			cin>>cad[i];
			k = cad[i];

			if (k == 'R')
				dis[i] = dist;
			if (k == 'Z'){
				dist = 0;
				dis[i] = dist;
			}
			if (k == 'D')
				dist = 0;

			dist++;
		}
		dist = INF;
		int res = INF;
		for (int i = n-1; i >= 0; i--){
			k = cad[i];
			if (k == 'R')
				dis[i] = min(dis[i], dist);
			if (k == 'Z'){
				dist = 0;
				dis[i] = min(dis[i], dist);
			}
			if (k == 'D')
				dist = 0;

			dist++;
			if (k == 'Z' || k == 'R')
				res = min(res, dis[i]);
		}

		cout<<res<<endl;
	}
	return 0;
}