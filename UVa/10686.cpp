#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <ctype.h>

using namespace std;

vector <string> split(string cad){
	vector <string> res;
	string buff = "";
	cad = cad + " ";
	for (int i = 0; i < cad.length(); i++){
		char k = cad[i];
		if (isalpha(k))
			buff = buff + k;
		else{
			if (buff != "")
				res.push_back(buff);
			buff = "";
		}

	}

	return res;
}


struct Category
{
	string name;
	set<string> keyWords;
	int nOfMatchs;
	int id;
	int minimum;
	Category(){};
	Category(string aName, int aMinimum, int aId){
		name = aName;
		nOfMatchs = 0;
		id = aId;
		minimum = aMinimum;
	}

	void match(string aWord){
		if (keyWords.find(aWord) != keyWords.end()){
			nOfMatchs++;
			keyWords.erase(aWord);
		}
	}

	void add(string aWord){
		keyWords.insert(aWord);
	}

	bool matches(){
		return nOfMatchs >= minimum;
	}
};

bool orden(Category a, Category b){
	return a.id < b.id;
}

int main(){

	int nTest;
	cin>>nTest;
	while (nTest--){
		int nOfCat;
		cin>>nOfCat;
		map <string, Category> categories;
		map <string, Category> :: iterator it;

		for (int i = 0; i < nOfCat; i++){
			string name;
			int nOfKey, required;
			cin>>name>>nOfKey>>required;
			categories[name] = Category(name, required, i);
			for (int j = 0; j < nOfKey; j++){
				string aKey;
				cin>>aKey;
				categories[name].add(aKey);
			}
		}

		cin.ignore();
		string line;
		while (getline(cin, line) && line != ""){
			vector <string> buffer = split(line);
			for (int i = 0; i < buffer.size(); i++){
				for (it = categories.begin(); it != categories.end(); it++){
					Category *aCat = &(categories[it->first]);
					aCat->match(buffer[i]);
				}
			}
		}

		vector <Category> res;

		for (it = categories.begin(); it != categories.end(); it++){
			Category aCat = it->second;
			if (aCat.matches())
				res.push_back(aCat);
		}

		sort(res.begin(), res.end(), orden);

		if (res.size() > 0){
			cout<<res[0].name;
			for (int i = 1; i < res.size(); i++)
				cout<<','<<res[i].name;

			cout<<endl;
		}
		else
			cout<<"SQF Problem."<<endl;
	}
	return 0;
}