#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;


string build(int n, bool car){
	string res(n, '*');

	for (int i = 0; i < n; i++){
		res[i] = car ? 'A' : 'B';
		car = !car;
	}

	return res;
}

int dif(string &cad1, string &cad2){
	int n = cad1.length();
	int res = 0;
	for (int i = 0; i < n; i++){
		if (cad1[i] != cad2[i])
			res++;
	}

	return res;
}

char pick(char a, char b){
	char res = 'A';

	while (res == a || res == b)
		res++;
//	cout<<"a: "<<a<<" b: "<<b<<" picked: "<<res<<endl;
	return res;
}

int main()
{
	int n, k;
	string cad;
	cin>>n>>k>>cad;

	if (k == 2){
		string c1 = build(n, true);
		string c2 = build(n, false);
		int def1 = dif(c1, cad);
		int def2 = dif(c2, cad);

		if (def1 > def2){
			cout<<def2<<endl<<c2<<endl;
		}
		else
			cout<<def1<<endl<<c1<<endl;
	} else {
		int res = 0;
		for (int i = 1; i < n; i++){
			if (cad[i] == cad[i-1]){
				if (i == n-1){
					cad[i] = pick(cad[i], cad[i]);
				}
				else
					cad[i] = pick(cad[i], cad[i+1]);
				res++;
			}
		}

		cout<<res<<endl<<cad<<endl;
	}

	return 0;
}