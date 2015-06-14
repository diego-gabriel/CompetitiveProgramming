#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

map <char, vector <char> > graph;
map <char, bool> open, finished;
stack <char> pila;
bool ok;

void build (string upper, string lower){
	int i, j;
	i = 0;
	while (i < upper.length() && i < lower.length() && upper[i] == lower[i]){
		i++;
	}

	if (i < upper.length() && i < lower.length()){
		graph[upper[i]].push_back(lower[i]);
	}
	else
		ok = upper.length() <= lower.length();
}

void dfs(char k){
	if (open[k]){
		ok = false;
	}
	else{
		open[k] = true;
	
		for (int i = 0; i < graph[k].size(); i++)
			if (!finished[graph[k][i]])
				dfs(graph[k][i]);
	
		open[k] = false;
		pila.push(k);
	}
	finished[k] = true;
}

int main(){
	ok = true;

	int n;
	cin>>n;
	string a, b;
	cin>>a;
	for (int i = 1; i < n; i++){
		cin>>b;
		build(a, b);
		a = b;
	}

	for (char k = 'a'; k <= 'z'; k++)
		if (!finished[k])
			dfs(k);
	if (ok){
		while (!pila.empty())
		{
			cout<<pila.top();
			pila.pop();
		}
		cout<<endl;
	}
	else
		cout<<"Impossible"<<endl;

	return 0;
}