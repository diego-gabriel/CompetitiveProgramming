#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string toString(int n){
	string res = "";
	//cout<<"in: "<<n<<endl;
	while (n){
		res = ((char)(n%10 + '0')) + res;
		n /= 10;
	}
	//cout<<"out: "<<res<<endl;

	return res;
}

struct Vec
{
	vector <int> componentes;
	int value;
	int id;
	Vec(){};
	void read(int n, int i){
		id = i;
		int a;
		cout<<"vector "<<i<<" reads: "<<endl;
		do{
			scanf("%d", &a);
			componentes.push_back(a);
			cout<<a<<endl;
		} while (getchar() != '\n');

		cout<<"end read "<<i<<endl;
	}

	void readV(){
		scanf("%d", &value);
	}
};

int n, m;
bool ld(Vec &a, Vec &b){
	int num, den;
	num = 0;
	den = 0;
	int i = 0;
	while (a.componentes[i] == 0 && b.componentes[i] == 0)
		i++;

	if ((a.componentes[i] == 0 && b.componentes[i] != 0)
		|| (b.componentes[i] == 0 && a.componentes[i] != 0))
		return false;

	num = a.componentes[i];
	den =  b.componentes[i];
	i++;
	while (i < n){
		if (a.componentes[i] == 0 && b.componentes[i] == 0){
			i++;
			continue;
		}
		if ((a.componentes[i] == 0 && b.componentes[i] != 0)
			|| (b.componentes[i] == 0 && a.componentes[i] != 0))
			return false;
		if (den * a.componentes[i] != b.componentes[i] * num)
			return false;
		i++;
	}
	return true;
}

bool orden(Vec a, Vec b){
	if (a.value == b.value)
		return toString(a.id) < toString(b.id);
	return a.value < b.value;
}

int main(){
	cin>>m>>n;
	Vec vectores[m];
	bool vis[m];
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < m; i++)
		vectores[i].read(n, i+1);

	for (int i = 0; i < m; i++)
		vectores[i].readV();
	vector <Vec> candidatos;
	Vec cand;

	for (int i = 0; i < m; i ++){
		cout<<vectores[i].componentes.size()<<" - "<<n<<endl;

		if (vis[i] || vectores[i].componentes.size() != n)
			continue;
		cout<<"lalalala"<<endl;
		cand = vectores[i];
		for (int j = i+1; j < m; j++){
			if (vis[j] || vectores[j].componentes.size() != n)
				continue;
			cout<<"lal"<<endl;
			if (ld(cand, vectores[j])){
				vis[j] = true;
				if (cand.value > vectores[j].value)
					cand = vectores[j];
			}
		}
		candidatos.push_back(cand);
	}

	if (candidatos.size() >=  n){
		sort(candidatos.begin(), candidatos.end(), orden);


		for (int i = 0; i < candidatos.size(); i++)
			cout<<candidatos.at(i).id<<endl;



		int total = 0;
		set <string> res;
		set <string> :: iterator it;
		for (int i = 0; i < n; i++){
			total += candidatos[i].value;
			res.insert(toString(candidatos[i].id));
		}
		printf("%d\n", total);
		for (it = res.begin(); it != res.end(); it++){
			cout<<*it<<endl;
		}

	}
	else
		printf("0\n");

	return 0;
}