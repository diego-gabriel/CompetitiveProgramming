#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
	int x;
	cin>>x;
	vector<string> init;
	map <string, string> change;
	map <string, bool> vis;
	string o, n;
	for (int i = 0; i < x; i++){
		cin>>o>>n;
		init.push_back(o);
		change[o] = n;
		change[n] = "";
		vis[o] = false;
		vis[n] = false;
	}

	int res = 0;
	vector <string> r;
	for (int i = 0; i < init.size(); i++){
		if (!vis[init[i]]){
			string handle = init[i];
			res++;
			r.push_back(handle);
			while (change[handle] != ""){
				vis[handle] = true;
				handle = change[handle];
			}
			r.push_back(handle);
		}
	}
	cout<<res<<endl;
	for (int i = 0; i < r.size(); i+=2)
		cout<<r[i]<<" "<<r[i+1]<<endl;

	return 0;
}	