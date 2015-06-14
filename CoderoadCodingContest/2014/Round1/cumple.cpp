#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		int n, m;
		cin>>n>>m;
		vector <int> regalos;
		int suma, res;
		suma = res = 0;
		int v;
		for (int i = 0; i < n; i++){
			cin>>v;
			regalos.push_back(v);
		}

		sort(regalos.begin(), regalos.end());

		for (int i = 0; i < n; i++){
			suma += regalos[i];
			if (suma > m) break;
			res++;
		}

		cout<<res<<endl;
	}
	return 0;
}