#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long pow(long long b, long long e){
	long long res;

	if (e <= 0)
		res = 1;
	else{
		long long aux;
		if (e % 2 == 0){
			aux = pow(b, e/2);
			res = (aux * aux) % MOD;
		}
		else{
			res = (pow(b, e-1) * b) % MOD;
		}
	}

	return res;
}

struct Edge
{
	long long carryID;
	long long layer;
	long long id;
	long long toLayer;
	long long toId;
	bool isEnd;

	Edge(){};
	Edge(long long a, long long b, long long c, bool end){
		layer = a;
		id = b;
		carryID = c;
		isEnd = end;
	}
	Edge(long long a, long long b, long long c, long long d, long long e, bool end){
		layer = a;
		id = b;
		toLayer = c;
		toId = d;
		carryID = e;
		isEnd = end;
	}

};

bool operator < (Edge a, Edge aEdge){
	if (a.layer == aEdge.layer){
		if (a.id == aEdge.id){
			return a.isEnd < aEdge.isEnd;
		}
		else
			return a.id < aEdge.id;
	}
	else
		return a.layer < aEdge.layer;
}	

long long min(long long a, long long b){
	return a < b ? a : b;
}

long long max(long long a, long long b){
	return a > b ? a : b;
}

int main(){
	long long n, m, k;
	cin>>n>>m>>k;
	vector <Edge> edges;
	map <int, map <int, long long > > carries;
	long long a, b, c, d;

	long long res = 1;
	for (long long i = 0; i < k; i++){
		cin>>a>>b>>c>>d;
		edges.push_back(Edge(a, b, c, d, i, false));
		edges.push_back(Edge(c, d, i, true));
	}

	sort(edges.begin(), edges.end());

	long long lastLayer = 0;
	for (long long i = 0; i < edges.size(); i++){
		Edge aEdge = edges[i];
		long long currentLayer = aEdge.layer;

		long long onLast = (res * pow(m, aEdge.layer - lastLayer - 1)) % MOD;
		if (currentLayer == n+1)
			res = onLast;
		else
			res = (res * pow(m, aEdge.layer - lastLayer)) % MOD;

		lastLayer = aEdge.layer;
		do{
			aEdge = edges[i];

			if (aEdge.isEnd){
				res += carries[aEdge.layer][aEdge.id];
				carries[aEdge.layer][aEdge.id] = 0;
				res %= MOD;
			}
			else{
				carries[aEdge.toLayer][aEdge.toId] = (carries[aEdge.toLayer][aEdge.toId] + onLast + carries[aEdge.layer][aEdge.id]) % MOD;
			}
			i++;
		} while (aEdge.layer == edges[i].layer);		
		i--;
	}

	res = (res * pow(m, n+1 - lastLayer - 1)) % MOD;
	cout<<res<<endl;

	return 0;
}