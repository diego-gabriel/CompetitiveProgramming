#include <iostream>
#include <map>
#include <cstring>
#include <ctype.h>
#include <cstdio>

using namespace std;

int m(char k){
	int res = 0;
	if (isdigit(k))
		res = k-'0';
	else{
		//cout<<"xD"<<endl;
		if (k == 'A' || k == 'B' || k == 'C')
			res = 2;
		if (k == 'D' || k == 'E' || k == 'F')
			res = 3;
		if (k == 'G' || k == 'H' || k == 'I')
			res = 4;
		if (k == 'J' || k == 'K' || k == 'L')
			res = 5;
		if (k == 'M' || k == 'N' || k == 'O')
			res = 6;
		if (k == 'P' || k == 'R' || k == 'S')
			res = 7;
		if (k == 'T' || k == 'U' || k == 'V')
			res = 8;
		if (k == 'W' || k == 'X' || k == 'Y')
			res = 9;
	}	
	return res;
}

int f(string t){
	int res = 0;

	for (int i = 0; i < t.size(); i++){
		if (t[i] != '-'){
			res*= 10;
			res += m(t[i]);
		//	cout<<t[i]<<" -> "<<m(t[i])<<endl;
		}
	}
	return res;
}

int main(){

	int n;
	cin>>n;
	while (n--){

		map <int, int> times, res;
		map <int, int> :: iterator it;
		times.clear();
		int t;
		cin>>t;
		for (int i = 0; i < t; i++){
			string tel;
			cin>>tel;
			times[f(tel)]++;
		//	cout<<tel<<" -> "<<f(tel)<<endl;
		}

		for (it = times.begin(); it != times.end(); it++){
			if (it->second > 1)
				res[it->first] = it->second;
		}

		if (res.empty())
			cout<<"No duplicates."<<endl;
		else
		{
			for (it = res.begin(); it != res.end(); it++){
				printf("%03d-%04d %d\n", it->first/10000, it->first%10000, it->second);
			}
		}
		if (n)
			cout<<endl;
	}
	return 0;
}