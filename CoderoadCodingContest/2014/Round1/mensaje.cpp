#include <bits/stdc++.h>

using namespace std;

string cad;

int solve(int i, int s){
	int res = 0;
	//ty9?ODC(oD3rOAD
	if (s == 8)
		res = 1 + solve(i, 0);
	else
	if (i < cad.length())
	{
		char k = cad[i];
		if (s == 0 && (k == 'C' || k == 'c' || k == '('))
			res = solve(i+1, 1);
		else
		if (s == 1 && (k == 'o' || k == '0' || k == 'O'))
			res = solve(i+1, 2);
		else
		if (s == 2 && (k == 'd' || k == 'D'))
			res = solve(i+1, 3);
		else
		if (s == 3 && (k == 'e' || k == 'E' || k == '3'))
			res = solve(i+1, 4);
		else
		if (s == 4 && (k == 'R' || k == 'r'))
			res = solve(i+1, 5);
		else
		if (s == 5 && (k == 'o' || k == '0' || k == 'O'))
			res = solve(i+1, 6);
		else
		if (s == 6 && (k == 'A' || k == 'a' || k == '@'))
			res = solve(i+1, 7);
		else
		if (s == 7 && (k == 'd' || k == 'D'))
			res = solve(i+1, 8);
		else
		if (k == 'C' || k == 'c' || k == '(')
			res = solve(i+1, 1);
		else 
			res = solve(i+1, 0);
	}

//	cout<<"i: "<<i<<" s: "<<s<<" k: "<<cad[i]<<endl;
//	cout<<"length: "<<cad.length()<<endl;
	return res;
}

int main(){

	int nTest;
	cin>>nTest;

	for (int test = 0; test < nTest; test++){
		int n;
		cin>>n>>cad;
		cout<<"Caso #"<<test+1<<": ";
		cout<<solve(0, 0)<<endl;

	}
	return 0;
}