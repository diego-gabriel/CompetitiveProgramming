#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Server
{
	unsigned long long capacity;
	int volt;
	int id;
	Server(){}
	Server(unsigned long long c, int v, int i){
		volt = v;
		capacity = c;
		id = i;
	}
};

bool ord(Server a, Server b){
	if (a.capacity == b.capacity)
		return a.volt > b.volt;
	else
		return a.capacity > b.capacity;
}

int main(){

	unsigned long long n, target;

	vector <Server> s, res;
	unsigned long long cap;
	bool v;
	cin>>n>>target;
	for (int i = 1; i<= n; i++){
		cin>>cap>>v;
		s.push_back(Server(cap, v, i));
	}

	sort(s.begin(), s.end(), ord);
	unsigned long long sum = 0;

	int c = 0;
	int low = 0;
	while (sum < target){
		sum += s[c].capacity;
		res.push_back(s[c]);
		c++;
	}

	int l, r;
	r = c;
	l = 0;
	//cout<<"c: "<<c<<endl;

	while (c < s.size() && l < res.size()){
		//cout<<"ok"<<endl;
		if (res[l].volt == 0){
			//cout<<"high found"<<endl;
			if (s[c].volt == 1 && sum - res[l].capacity + s[c].capacity >= target){
				//cout<<"low to replace"<<endl;
				sum = sum - res[l].capacity && s[c].capacity;
				res[l] = s[c];
				c++;
			}
			else
				c++;
		}
		else
			l++;
	}

	for (int i = 0; i < res.size(); i++)
		if (res[i].volt == 1)
			low++;

	cout<<res.size()<<" "<<low<<endl;
	cout<<res[0].id;
	for (int i = 1; i < res.size(); i++)
		cout<<" "<<res[i].id;
	cout<<endl;

	return 0;
}