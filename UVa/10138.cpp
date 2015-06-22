#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long v[24];

long long toInt(string cad){
	long long res = 0;

	for (long long i = 0, n = cad.length(); i < n; i++){
		res *= 10;
		res += (cad[i] - '0');
	}

	return res;
}

vector<string> split(string cad, char k){
	vector<string> res;
	string buf = "";
	cad = cad + k;
	for(long long i = 0, n = cad.length(); i < n; i++){
		if (cad[i] == k){
			if (buf != "")
				res.push_back(buf);
			buf = "";
		} else {
			buf = buf + cad[i];
		}
	}

	return res;
}

struct Time
{
	long long d;
	long long m;
	long long h;
	long long s;

	Time(){}
	Time(string cad){
		vector<string> v = split(cad, ':');
		d = toInt(v[0]);
		m = toInt(v[1]);
		h = toInt(v[2]);
		s = toInt(v[3]);
	}
};

struct Entry
{
	string id; 
	Time t;
	string op;
	long long km;

	Entry(){}
	Entry(string cad){
		vector<string> v = split(cad, ' ');
		id = v[0];
		t = Time(v[1]);
		op = v[2];
		km = toInt(v[3]);
	}
};

bool operator < (Time a, Time b){
	if (a.m == b.m){
		if (a.d == b.d){
			if (a.h == b.h)
				return a.s < b.s;
			else
				return a.h < b.h;
		}
		else
			return a.d < b.d;
	} 
	else
		return a.m < b.m;
}

bool operator < (Entry a, Entry b){
	return a.t < b.t;
}


void solve(string id, set<Entry> entries){
	set<Entry>:: iterator it;

	long long tot = 200;
	it = entries.begin();
	Entry last = *it;
	Entry current;
	it++;

	while (it != entries.end()){
	
		current = *it;

		if (last.op == "enter" && current.op == "exit"){
			tot += (100 + abs(current.km-last.km)*v[last.t.h]);
		}
		last = current;
		it++;
	}	

	if (tot > 200)
	{
		cout<<id;
		printf(" $%lld.%02lld\n", tot/100, tot%100);
	}
}

int main(){
	long long n;
	cin>>n;

	while (n--){

		for(long long i = 0; i < 24; i++)
			cin>>v[i];
	
		string cad;
		cin.ignore();
		map <string, set<Entry> > entries;
		map <string, set<Entry> > :: iterator it;

		Entry aEntry;
	
		while (getline(cin, cad) && cad != ""){
			aEntry = Entry(cad);
			entries[aEntry.id].insert(aEntry);
		}

		for(it = entries.begin(); it != entries.end(); it++){
			solve(it->first, it->second);
		}

		if (n) cout<<endl;
	}
	return 0;
}