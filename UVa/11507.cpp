#include <iostream>
#include <map>
#include <cstring>

using namespace std;

map <string, map <string, string> > state;

void init(){

	state["+x"]["+y"] = "+y";
	state["+x"]["-y"] = "-y";
	state["+x"]["+z"] = "+z";
	state["+x"]["-z"] = "-z";
	state["+x"]["No"] = "+x";

	state["-x"]["+y"] = "-y";
	state["-x"]["-y"] = "+y";
	state["-x"]["+z"] = "-z";
	state["-x"]["-z"] = "+z";
	state["-x"]["No"] = "-x";

	state["+y"]["+y"] = "-x";
	state["+y"]["-y"] = "+x";
	state["+y"]["+z"] = "+y";
	state["+y"]["-z"] = "+y";
	state["+y"]["No"] = "+y";

	state["-y"]["+y"] = "+x";
	state["-y"]["-y"] = "-x";
	state["-y"]["+z"] = "-y";
	state["-y"]["-z"] = "-y";
	state["-y"]["No"] = "-y";

	state["+z"]["+y"] = "+z";
	state["+z"]["-y"] = "+z";
	state["+z"]["+z"] = "-x";
	state["+z"]["-z"] = "+x";
	state["+z"]["No"] = "+z";

	state["-z"]["+y"] = "-z";
	state["-z"]["-y"] = "-z";
	state["-z"]["+z"] = "+x";
	state["-z"]["-z"] = "-x";
	state["-z"]["No"] = "-z";
}

int main(){
	int l;
	init();
	while (cin>>l && l){
		string s;
		string status = "+x";
		for (int i = 0; i < l-1; i++){
			cin>>s;
			status = state[status][s];
		}
		cout<<status<<endl;
	}
	return 0;
}