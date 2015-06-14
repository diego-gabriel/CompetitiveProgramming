#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

string cad;
int test;
int res;
int p;
int id;
struct Nodo{
	map<char, Nodo> nod;
	int it;
	Nodo(){
		nod.clear();
	}

	bool contains(char k){
		bool res = nod.find(k) != nod.end();
		return res;
	}

	int size(){
		return nod.size();
	}

	Nodo* get(char k){
		if (!contains(k))
			nod[k] = Nodo();
		return &(nod[k]);	
	}

};

void insert(Nodo &nodo){
	Nodo* n = &nodo;
	for (int i = 0; i < cad.length(); i++){
		char k = cad[i];
		if ((n->size()) > 0) {
			p++;
		}

		n = n->get(k);
	}
}

int main(){
	int nTest;
	cin>>nTest;

	Nodo tree;

	for (test = 1;test <= nTest;  test++){
		int n;
		cin>>n;
		for (char k = 'a'; k <= 'z'; k++)
			tree.nod[k] = Nodo();
		res = 0;

		for (int i = 0; i < n; i++){
			cin>>cad;
			cad = cad + "$";
			p = 0;
			insert(tree);

			if (p > cad.length()-1)
				p = cad.length()-1;
			//cout<<cad<<" -> "<<p<<endl;

			res += p;
		}

		cout<<"Case #"<<test<<": "<<res<<endl;

	}
	return 0;
}