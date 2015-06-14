#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int r, g, b, m;
		cin>>r>>g>>b>>m;
		int R, G, B;
		R = G = B = 0;
		int v;
		for(int i = 0; i < r; i++){
			cin>>v;
			R = max(R, v);
		}
		for(int i = 0; i < g; i++){
			cin>>v;
			G = max(G, v);
		}
		for(int i = 0; i < b; i++){
			cin>>v;
			B = max(B, v);
		}

		for (int i = 0; i < m; i++){
			if (R >= G && R >= B){
				R = R / 2;
			}
			else
			if (B >= R && B >= G)
				B = B / 2;
			else
			if (G >= R && G >= B)
				G = G / 2;

		}

		cout<<max(R, max(G, B))<<endl;
	}
	return 0;
}