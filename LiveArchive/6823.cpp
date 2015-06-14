#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

#define MAX 1000005
long long memo[MAX][3];
string cad;

long long toInt(char k){
	return k - '0';
}
/*
long long solve(long long i, long long mod){
	long long res = 0;

	if (i < cad.length() && !solved[i][mod]){
		solved[i][mod] = true;

		if (isdigit(cad[i])){
			if ((mod + toInt(cad[i])) % 3 == 0)
				res = 1;
			res += solve(i+1, (mod + toInt(cad[i])) % 3);
		}

		memo[i][mod] = res;
	}
	return memo[i][mod];
}
*/
int main(){
	while (cin>>cad){
		memset(memo, 0, sizeof(memo));
		long long res = 0;

		for(long long i = cad.length()-1; i >= 0; i--){
			for (int mod = 0; mod < 3; mod++){
				if (isdigit(cad[i])){
					if ((mod + toInt(cad[i])) % 3 == 0)
						memo[i][mod] = 1;
					memo[i][mod] += memo[i+1][(mod + toInt(cad[i])) % 3];
				}
			}
			res += memo[i][0];
		}
		cout<<res<<endl;
	}
	return 0;
}