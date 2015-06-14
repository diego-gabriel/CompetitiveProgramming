#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;


map <string, string> genOf;
map <string, set<string> > parentsOf;

struct Person
{
	string name;
	string gen;

	Person(){};
	Person(string a, string b){
		name = a;
		gen = b;
	}
};

bool operator < (Person a, Person b){
	return a.name < b.name;
}

bool is_a_gen(string &s){
	return s == "non-existent" || s == "recessive" || s == "dominant";
}
bool is_a_valid_gen(string &s){
	return s ==  "recessive" || s == "dominant";
}


bool is_dominant(string &a, string &b){
	return a == "dominant" || b == "dominant";
}

bool is_recessive(string &a, string &b){
	return a == "recessive" || b == "recessive";
}

bool has_the_gen(string &a, string &b){
	return (is_a_valid_gen(a) && is_a_valid_gen(b)) || is_dominant(a, b);
}



string solve(set<string> parents){
	string res = "";

	if (parents.size() == 1){
		res = genOf[*(parents.begin())];
	}
	else {
		set<string> :: iterator it;
		it = parents.begin();
		string p1, p2;
		p1 = *it;
		it++;
		p2 = *it;

		p1 = solve(parentsOf[p1]);
		p2 = solve(parentsOf[p2]);

		if (has_the_gen(p1, p2)){
			if ((p1 == "dominant" && p2 == "dominant") || (p1 == "recessive" && p2 == "dominant") || (p1 == "dominant" && p2 == "recessive"))
				res = "dominant";
			else
				res = "recessive";
		}
		else
			res = "non-existent";
	}

	return res;
}

int main(){

	int n;
	while(cin>>n){
		Person aPerson;
		string name, gen;
		for (int i = 0; i < n; i++){
			cin>>name>>gen;
			if (is_a_gen(gen)){
				genOf[name] = gen;
				parentsOf[name].insert(name);
			}
			else {
				parentsOf[gen].insert(name);
				genOf[gen] = "none";
			}
		}
		
		map <string, string> :: iterator it;

		for (it = genOf.begin(); it != genOf.end(); it++){
			if (!is_a_gen(it->second))
				genOf[it->first] = solve(parentsOf[it->first]);
			cout<<it->first<<" "<<genOf[it->first]<<endl;
		}

	}
	return 0;
}