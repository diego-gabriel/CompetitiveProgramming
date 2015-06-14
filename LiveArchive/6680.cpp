#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct Msg
{
	string message;
	int  id;
	Msg(){};
	Msg(string m, int i){
		message = m;
		id = i;
	}
};

map <string, vector<Msg> > list;

string getUser(string &message){
	string res = "";
	int i = 0;
	while (message[i] != ':'){
		res = res + message[i];
		i++;
	}
	return res;
}

vector <string> getReferences(string &message){
	vector <string> res;
	bool skip = true;
	string user = "";
	int ini = 0;
	for (int i = 0; i < message.length(); i++){
		if (skip){
			skip = message[i] != ':';
			ini = i;
		}
		else{
			if (message[i] == '@' && (message[i-1] == ' ' || i == ini+1)){
				if (list.find(user) != list.end()){
					res.push_back(user);
				}
				user = "@";
			}
			else
			if (message[i] = ' ')
		}
	}
	return res;
}

int main(){
	int n;
	while (cin>>n){
		string message, user;
		list.clear();
		cin.ignore();

		for (int i = 1; i <= n; i++){
			getline(cin, message);
			user = getUser(message);
			vector <string> references = getReferences(message);
		}
	}
	return 0;
}