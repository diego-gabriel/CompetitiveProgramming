#include <iostream>
#include <set>

using namespace std;

struct Info
{
	int value, id;
	Info();
	Info(int v, int i){
		value = v;
		id = i;
	}
};

bool operator < (Info a, Info b){
	if (a.value == b.value)
		return a.id < b.id;
	return a.value < b.value;
}

int main(){
	int nTest;

	cin>>nTest;

	while (nTest--){
		int b, p;
		cin>>b>>p;
		int val[p+2];
		int dist[p+2];
		for (int i = 1; i <= p; i++){
			cin>>val[i];
		}

		for (int i = 0; i < p+2; i++){
			dist[i] = 0x0fffffff;
		}
		set<Info> cola;
		cola.insert(Info(0, 0));
		while (!cola.empty()){
			
		}


		cout<<dist[p+1]<<endl;

	}
}