#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007
long long memo1[2002][2002];
long long memo2[2002][2002];

bool sf(long long a, long long b){
	return a > b;
}

long long stressfree(long long a, long long b, long long me, long long op){
	if (memo1[a][b] == -1){
		long long res = 0;
		if (a == me && op == b)
			res = 1;
		else{
			if (sf(a, b+1) && b+1 <= op)
				res += stressfree(a, b+1, me, op);
			if (a+1 <= me)
				res += stressfree(a+1, b, me, op);
			res %= MOD;
		}

		memo1[a][b] = res;
	}

	return memo1[a][b];
}

bool sfull(long long a, long long b, long long top){
	return a <= b || b == top;
}

long long stressfull(long long a, long long b, long long me, long long op){

	if (memo2[a][b] == -1){
		long long res = 0;
		if (a == me && b == op){
			res = 1;
		}
		else{
			if (sfull(a+1, b, op) && a+1 <= me)
				res += stressfull(a+1, b, me, op);
			if (b+1 <= op)
				res += stressfull(a, b+1, me, op);
			res %= MOD;
		}
		memo2[a][b] = res;
	}
	return memo2[a][b];	
}

long long toInt(string cad){
	long long res = 0;

	for (long long i = 0; i < cad.length(); i++){
		res *= 10;
		res += (cad[i] - '0');
	}

	return res;
}

pair<long long, long long> parse(string cad){
	string a = "";

	long long i = 0;
	while (cad[i] != '-'){
		a = a + cad[i];
		i++;
	}

	return make_pair(toInt(a), toInt(cad.substr(i+1)));
}



void init(){
	long long  n = 2002;
	for (long long i = 0; i < n; i++){
		for (long long j = 0; j < n; j++){
			memo2[i][j] = -1;
			memo1[i][j] = -1;
		}
	}
}

int main(){
	long long nTest;
	cin>>nTest;

	for (long long test = 1; test <= nTest; test++){
		init();
		string cad;
		cin>>cad;
		pair<long long, long long> p = parse(cad);
		long long a = p.first;
		long long b = p.second;
	//	cout<<"readed: "<<a<<" "<<b<<endl;
		cout<<"Case #"<<test<<": "<<stressfree(0, 0, a, b)<<" "<<stressfull(0, 0, a, b)<<endl;

	}
	return 0;
}