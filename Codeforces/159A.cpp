#include <iostream>
#include <map>
#include <vector>
using namespace std;
map <string, map <string, bool> > ex;
vector <pair<string, string> > res;

struct Message
{
	string sender, receiver;
	int timestamp;
	Message(){
	}
	Message(string a, string b, int t){
		sender = a;
		receiver = b;
		timestamp = t;
	}
};

bool operator == (Message a, Message b){
	return a.sender == b.receiver && a.receiver == b.sender;
}

int main(){
	int n, d;
	cin>>n>>d;

	Message mes[n];
	for (int i = 0; i < n; i++){
		cin>>mes[i].sender>>mes[i].receiver>>mes[i].timestamp;
	}

	for (int i = 0; i < n; i++){
		for (int t =i+1; t < n; t++)
		{
			if (mes[i] == mes[t] && (mes[t].timestamp-mes[i].timestamp <= d) && (mes[t].timestamp-mes[i].timestamp > 0)){
				string o, des;
			//	cout<<mes[t].timestamp<<"-"<<mes[i].timestamp<<endl;
			//	cout<<mes[t].timestamp-mes[i].timestamp << " vs "<<d<<endl;
				o = mes[i].sender;
				des = mes[i].receiver;
			//	cout<<"->"<<o<<" "<<d<<endl;
				if (!ex[o][des]){
					ex[o][des] = true;
					ex[des][o] = true;
					res.push_back(make_pair(o, des));
				}
			}
		}
	}

	cout<<res.size()<<endl;

	for (int i = 0; i < res.size(); i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}

	return 0;
}