#include <iostream>
#include <cstring>

using namespace std;

void add(string &s){
	int c[s.length()];

	for (int i = 0; i < s.length(); i++){
		c[i] = s[i]-'a';
	}
	int z = 'z'-'a' + 1;
	c[s.length()-1]++;
	for (int i = s.length()-1; i >= 0; i--){
		if (i-1 >= 0)
			c[i-1] += c[i]/z;
		c[i] %= z;
	}

	for (int i = 0; i < s.length(); i++){
		s[i] = c[i] + 'a';
	}

}

int main(){
	string s, t;
	cin>>s>>t;

	add(s);

	if (s < t)
		cout<<s<<endl;
	else
		cout<<"No such string"<<endl;

	return 0;
}