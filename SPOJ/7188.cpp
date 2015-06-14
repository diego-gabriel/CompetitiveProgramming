#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main(){
	int n, k, m;

	while (cin>>n>>k>>m && (n != -1 || m != -1 || k != -1)){
		set<int> disLock, keys;
		vector <int> hasKey;
		hasKey.assign(n+5, -1);
		vector <bool> locked, visited;
		locked.assign(n+5, false);
		visited.assign(n+5, false);
		int a, b;
		for (int i = 0; i < k; i++){
			cin>>a>>b;
			hasKey[a] = b;
			locked[b] = true;
		}

		map <int, vector <int> > grafo;
		int origen, destino;
		for(int i = 0; i < m; i++){
			cin>>origen>>destino;
			grafo[origen].push_back(destino);
			grafo[destino].push_back(origen);
		}

		queue<int> cola;
		cola.push(1);
		visited[1] = true;

		while (!cola.empty()){
			origen = cola.front();
			cola.pop();
			//cout<<"enter into chamber: "<<origen<<endl;
			if (hasKey[origen] != -1){
				int key = hasKey[origen];
			//	cout<<"found key "<<key<<" on "<<origen<<endl;
				if (disLock.find(key) != disLock.end()){
					disLock.erase(key);
					cola.push(key);
				}
				else
					keys.insert(key);

			}

			for (int i = 0; i < grafo[origen].size(); i++){
				destino = grafo[origen][i];
				if (!visited[destino]){
					visited[destino] = true;
			//		cout<<"destino a "<<destino<<" desde "<<origen<<endl;
					if (locked[destino] && keys.find(destino) == keys.end()){
						disLock.insert(destino);
			//			cout<<"locked = "<<destino<<endl;
					}
					else{
						cola.push(destino);
						keys.erase(destino);
					}
				}
			}
		}

		if (visited[n])
			cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}