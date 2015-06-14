#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

long long nOfb(string cad){
	long long res = 0;
	for (long long i = 0; i < cad.length(); i++)
		if (cad[i] == 'B')
			res++;
	return res;
}

int main(){
	long long a, b;
	while (cin>>a>>b){
		long long great = a;
		long long small = a - b;

		string cad;
		cin>>cad;
		long long n = nOfb(cad);
		stack<long long> posOfB;
		for (long long i = n; i < cad.length(); i++)
			if (cad[i] == 'B')
				posOfB.push(i);

		long long res = 0;

		for (long long i = 0; i < n; i++){
			if (cad[i] == 'W'){
				long long lastB = posOfB.top();
				posOfB.pop();
				long long steps = lastB - i;
				if (steps*small < great)
					res += steps*small;
				else
					res += great;
			}
		}
		cout<<res<<endl;

	}
	return 0;
}