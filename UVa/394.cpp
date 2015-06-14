#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct Array
{
	string name;
	int B;
	int S;
	int D;
	vector<int> L;
	vector<int> U;
	vector<int> C;

	Array(){};
	Array(string a){
		name = a;
	}
	void read(string a){	
		name = a;
		cin>>B>>S>>D;
		int l, u;
		L.push_back(0);
		U.push_back(0);
		for (int i = 0; i < D; i++){
			cin>>l>>u;
			L.push_back(l);
			U.push_back(u);
		}
		C.assign(D+1, 0);
		C[D] = S;
		for (int i = D-1; i >= 1; i--){
			C[i] = C[i+1]*(U[i+1]-L[i+1]+1);
		}
		int x = 0;
		for (int i = 1; i <= D; i++)
			x += (C[i]*L[i]);

		C[0] = B - x;
	}

	void solve(vector <int> i){
		int res = 0;
		cout<<name<<"["<<i[0];
		res = C[0] + C[1]*i[0];

		for (int k = 1; k < i.size(); k++){
			res += (C[k+1]*i[k]);
			cout<<", "<<i[k];
		}

		cout<<"] = "<<res<<endl;
	}
};


int main(){
	int n, r;
	while (cin>>n>>r){
		map <string, Array> arrays;
		string cad;
		for (int i = 0; i < n; i++){
			cin>>cad;
			arrays[cad].read(cad);
		}

		vector <int> d;
		int v;
		for (int i = 0; i < r; i++){
			cin>>cad;
			d.clear();
			for (int j = 0, n = arrays[cad].D; j < n; j++){
				cin>>v;
				d.push_back(v);
			}
			arrays[cad].solve(d);
		}
	}
	return 0;
}