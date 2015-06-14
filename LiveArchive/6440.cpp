#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int nTest, n, t, r, test, i, s, j;
char k;

struct Paciente
{
	int t, s, r, val;
	Paciente(){};
	Paciente(int a, int b, int c){
		t = a;
		s = b;
		r = c;
		val = 0;
	}

	void act(int nt){
		val = s + r*(nt - t);
	}
};

vector <Paciente> pacientes;
Paciente pac;

bool orden (Paciente a, Paciente b){
	if (a.val == b.val)
		return a.r > b.r;
	return a.val > b.val;
}

int main(){
	scanf("%d\n", &nTest);
	for (test = 1; test <= nTest; test++){
		cout<<"Case #"<<test<<":"<<endl;
		scanf("%d\n", &n);
		pacientes.clear();
		for (i = 0; i < n; i++){
			scanf("%c", &k);
			if (k == 'P'){
				scanf("%d %d %d\n", &t, &s, &r);
				pacientes.push_back(Paciente(t, s, r));
			}
			if (k == 'A'){
				scanf("%d\n", &t);
				for (j = 0; j < pacientes.size(); j++){
					pacientes[j].act(t);
				}
				sort(pacientes.begin(), pacientes.end(), orden);
				pac = pacientes[0];
				pacientes.erase(pacientes.begin());
				cout<<pac.val<<" "<<pac.r<<endl;
			}
		}
	}
	return 0;
}