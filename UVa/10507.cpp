#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int max(int a, int b){
	return a < b ? b : a;
}

int main(){
	int slept, n;
	while (cin>>slept>>n){

		set<char> awake;
		map<char, set<char> > g;
		map<char, set<char> > :: iterator it;

		string cad;
		cin>>cad;
		awake.insert(cad[0]);
		awake.insert(cad[1]);
		awake.insert(cad[2]);

		for (int i = 0; i < n; i++){
			cin>>cad;
			char origen, destino;
			origen = cad[0];
			destino = cad[1];

			g[origen].insert(destino);
			g[destino].insert(origen);
		}
		int res = 0;
		while (awake.size() < slept){
			bool waken = false;
			set<char> wThis;
			for (it = g.begin(); it != g.end(); it++){

				char origen = it->first;
				if (awake.find(origen) != awake.end())
					continue;
				//cout<<"checking: "<<origen<<endl;
				set<char> :: iterator that;
				int waked = 0;
				for (that = g[origen].begin(); that != g[origen].end(); that++){
					char v = *that;
				//	cout<<"    vecino: "<<v;
					if (awake.find(v) != awake.end())
						waked++;
				//	cout<<" "<<waked<<endl;
				}

				if (waked >= 3){
					wThis.insert(origen);
				//	cout<<"waked "<<origen<<endl;
					waken = true;
				}
			}

			set<char> :: iterator tt;

			for (tt = wThis.begin(); tt != wThis.end(); tt++){
				awake.insert(*tt);
			}
		//	cout<<"round finished"<<endl;
			if (!waken)
				break;

			res++;
		}

		if (awake.size() < slept)
			cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
		else
			cout<<"WAKE UP IN, "<<res<<", YEARS"<<endl;

	}
	return 0;
}