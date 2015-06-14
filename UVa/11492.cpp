#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x07ffffff

struct Arista
{
	string destino;
	char letra;
	int peso;
	Arista(){
		destino = "";
		letra = peso = 0;
	}

	Arista(string dest, char k, int p){
		destino = dest;
		letra = k;
		peso = p;
	}	
};

struct List{
	int car['z' - 'a'];
	List(){
		for (int i = 0; i < 'z' - 'a'; i++)
			car[i] = INF;
	}

	void clear(){
		for (int i = 0 ; i < 'z' - 'a'; i++)
			car[i] = 0;
	}

	vector <pair<int, char> > getBestNot(char k){
		vector <pair<int, char> > res;
		int best = INF;

		for (int i = 0; i < 'z' -'a'; i++)
		{
			if (i + 'a' != k){
				if (car[i] < best){
					best = car[i];
					res.clear();
				}
				if (car[i] == best){
					res.push_back(make_pair(best, i + 'a'));
				}
			}
		}


		return res;
	}

	int min(int a, int b){
		return a < b ? a : b;
	}

	int getBest(){
		int res = INF;

		for (int i = 0; i < 'z' - 'a'; i++){
			res = min(car[i], res);
		}

		return res;
	}
};

int main(){
	int n;
	string origen, destino;

	while (cin>>n && n){
		cin>>origen>>destino;

		string o, d, p;
		map <string, List> dist;
		map <string, vector<Arista> > grafo;

		dist[origen];
		dist[destino];

		for (int i = 0; i < n; i++){
			cin>>o>>d>>p;
			dist[o];
			dist[d];

			grafo[o].push_back(Arista(d, p[0], p.length()));
			grafo[d].push_back(Arista(o, p[0], p.length()));
		}


		queue <string> cola;
		dist[origen].clear();
		cola.push(origen);
		string origin, dest;

		while (!cola.empty())
		{
			cout<<"pass"<<endl;
			origin = cola.front();
			cola.pop();

			vector<Arista> listaVec = grafo[origin];

			for (int i = 0; i < listaVec.size(); i++)
			{
				Arista vecino = listaVec[i];
				vector<pair <int, char> > resTemp = dist[origin].getBestNot(vecino.letra);
				
				bool encola = false;
				for (int j = 0; j < resTemp.size(); j++)
				{
					int dOrigen = resTemp[j].first;
					char letra = resTemp[j].second;

					if (dOrigen + vecino.peso < dist[vecino.destino].car[letra]){
						dist[vecino.destino].car[letra] = dOrigen + vecino.peso;
						encola = true;
					}
				}

				if (encola) cola.push(vecino.destino);

			}
		}

		int res = dist[destino].getBest();
		cout<<"lala"<<endl;
		if (res == INF) cout<<"impossivel"<<endl;
		else cout<<res<<endl;

	}
}