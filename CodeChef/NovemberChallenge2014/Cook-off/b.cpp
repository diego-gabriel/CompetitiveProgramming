#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool solve(vector <int> &v, string cad, bool in){
	v.clear();
	bool res = true;
	int node = in*5 + cad[0]-'A';
	v.push_back(node);

	for (int i = 1; i < cad.length() && res; i++){
		if (cad[i] == cad[i-1]){
			if (in)
				node -= 5;
			else
				node += 5;
			in = !in;
		}
		else
		if (in){
			if (cad[i-1] == 'A'){
				if (cad[i] == 'C')
					node = 7;
				else
				if (cad[i] == 'D')
					node = 8;
				else
					res = false;

			}
			if (cad[i-1] == 'B'){
				if (cad[i] == 'E')
					node = 9;
				else
				if (cad[i] == 'D')
					node = 8;
				else
					res = false;

			}

			if (cad[i-1] == 'C'){
				if (cad[i] == 'A')
					node = 5;
				else
				if (cad[i] == 'E')
					node = 9;
				else
					res = false;

			}

			if (cad[i-1] == 'D'){
				if (cad[i] == 'A')
					node = 5;
				else
				if (cad[i] == 'B')
					node = 6;
				else
					res = false;

			}

			if (cad[i-1] == 'E'){
				if (cad[i] == 'B')
					node = 6;
				else
				if (cad[i] == 'C')
					node = 7;
				else
					res = false;

			}
		}
		else {

			if (cad[i-1] == 'A'){
				if (cad[i] == 'E')
					node = 4;
				else
				if (cad[i] == 'B')
					node = 1;
				else
					res = false;

			}
			if (cad[i-1] == 'B'){
				if (cad[i] == 'A')
					node = 0;
				else
				if (cad[i] == 'C')
					node = 2;
				else
					res = false;

			}

			if (cad[i-1] == 'C'){
				if (cad[i] == 'B')
					node = 1;
				else
				if (cad[i] == 'D')
					node = 3;
				else
					res = false;

			}

			if (cad[i-1] == 'D'){
				if (cad[i] == 'C')
					node = 2;
				else
				if (cad[i] == 'E')
					node = 4;
				else
					res = false;

			}

			if (cad[i-1] == 'E'){
				if (cad[i] == 'A')
					node = 0;
				else
				if (cad[i] == 'D')
					node = 3;
				else
					res = false;

			}
		}

		v.push_back(node);
	}

	return res;
}

int main(){
	int test;
	cin>>test;
	while (test--){
		vector <int> v;

		string cad;
		cin>>cad;
		if (solve(v, cad, false) || solve(v, cad, true)){
			for (int i = 0; i < v.size(); i++)
				cout<<v[i];
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}