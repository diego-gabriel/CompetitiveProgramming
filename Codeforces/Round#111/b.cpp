#include <iostream>
#include <algorithm>

using namespace std;

int n;
char f[200], s[200];

bool solve1(){
	int k = n/2;

	for(int i = 0; i < k; i++){
		if (f[i] >= s[i])
			return false;
	}
	return true;
}


bool solve2(){
	int k = n/2;

	for(int i = 0; i < k; i++){
		if (f[i] <= s[i])
			return false;
	}
	return true;
}

int main(){

	cin>>n;
	n *=2;
	for(int i = 0; i < n/2; i++)
		cin>>f[i];
	for(int i = 0; i < n/2; i++)
		cin>>s[i];

	sort(f, f+(n/2));
	sort(s, s+(n/2));

	if (solve1() || solve2())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}