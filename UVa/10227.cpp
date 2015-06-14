#include <iostream>
#include <cstdio>
#include <set>
#include <ctype.h>

using namespace std;

struct Person
{
	set <int> trees;
	Person(){};
	void add(int a){
		trees.insert(a);
	}
};

int toInt (string cad){
	int res = 0;
	for (int i = 0; i < cad.length(); i++){
		res *= 10;
		res += (cad[i] - '0');
	}
	return res;
}

pair <int, int> parse(string cad){
	string fst, scd;
	fst = scd = "";

	bool first = true;
	bool second = false;

	for (int i = 0; i < cad.length(); i++)
	{
		first = first && isdigit(cad[i]);
		second = !first && isdigit(cad[i]);

		if (first){
			fst = fst + cad[i];
		}

		if (second){
			scd = scd + cad[i];
		}
	}

	return make_pair(toInt(fst), toInt(scd));
}

void solve(){
	string cad;

	bool first = true;
	Person persons[105];

	int t, p;
	int nT, nP;

	while (getline(cin, cad) && cad != ""){

		pair <int, int> input = parse(cad);

		if (first) {
			first = false;
			nP = input.first;
			nT = input.second;
		} else {
			p = input.first;
			t = input.second;
			persons[p].add(t);
		}
	}
	set <set <int> > res;
	for (int i = 1; i <= nP; i++){
		res.insert(persons[i].trees);
	}


	cout<<res.size()<<endl;
}

int main(){
	int nTest;

	cin>>nTest;
	cin.ignore();
	string cad;
	getline(cin, cad);
	bool first = true;
	for (int i = 0; i < nTest; i++){
		if (!first)
			cout<<endl;

		solve();
		first = false;
	}
}