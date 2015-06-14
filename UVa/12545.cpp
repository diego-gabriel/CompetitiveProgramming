#include <iostream>
#include <cstring>

using namespace std;

int count(string cad, char k){
	int res = 0;

	for (int i = 0; i < cad.length(); i++)
		if (cad[i] == k)
			res++;

	return res;
}

int solve(string source, string target){
	int res = count(source, '?');
	int mz = 0;
	int mo = 0;
	for (int i = 0; i < source.length(); i++){
		if (source[i] == '1' && target[i] == '0')
			mo++;

		if (source[i] == '0' && target[i] == '1')
			mz++;
	}

	return res + mo + ((mz - mo) > 0 ? (mz - mo) : 0);

}

/*
000001001001
000011000010

0011??00
00010100
*/

int main(){

	int nTest;
	cin>>nTest;
	for(int test = 1; test <= nTest; test++){
		string S, T;
		cin>>S>>T;
		cout<<"Case "<<test<<": ";

		if (count(S, '1') > count(T, '1') || S.length() != T.length())
			cout<<-1;
		else
			cout<<solve(S, T);
		cout<<endl;
	}

	return 0;
}