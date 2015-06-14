#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define MAX 10000007

bool prime[MAX];
vector <int> primes, size;
int s(int i){
	return i == 0 ? 0 : 1 + s(i/10);
}

void init(){
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i <= sqrt(MAX); i++){
		if (prime[i]){
			for(int j = 2*i; j < MAX; j+=i)
				prime[j] = false;
		}
	}

	for (int i = 0; i < MAX; i++){
		if (prime[i]){
			primes.push_back(i);
			size.push_back(s(i));
		}
	}
}

int toInt(string n){
	int res = 0;

	for (int i = 0; i < n.length(); i++){
		res *= 10;
		res += (n[i] - '0');
	}

	return res;
}

bool contains(string num, int p){
	int freq[10];
	memset(freq, 0, sizeof(freq));

	for (int i = 0; i < num.size(); i++)
		freq[num[i]-'0']++;

	bool ok = true;
	
	while(p){
		freq[p%10]--;
		ok = ok && freq[p%10] >= 0;
		p /= 10;
	}
	return ok;
}

string take(int mask, string num){
	string res = "";
	//cout<<"mask "<<mask<<endl;
	for (int i = 0; i < num.size(); i++){
		int bit = 1 << i;
	//	cout<<bit<<" --";
		if (mask & bit)
			res = res + num[i];//, cout<<"on"<<endl;
	//	else cout<<"off"<<endl;
	}
	//cout<<"->"<<res<<endl;
	return res;
}

int main(){

	init();
	int n;
	cin>>n;
	map <int, bool> f;

	while(n--){
		f.clear();
		string cad;
		cin>>cad;
		int res = 0;
		sort(cad.begin(), cad.end());

		for (int i = 0; i < pow(2, cad.length()); i++){
			string num = take(i, cad);
			do{
				int numero = toInt(num);
				if (prime[numero] && !f[numero]){
					res++;
					f[numero] = true;
				}
			}while (next_permutation(num.begin(), num.end()));
		}
		cout<<res<<endl;
	}

	return 0;
}