#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long n;

int tam(long long a){
	return a == 0 ? 0 : 1 + tam (a/10);
}

long long rev(long long i){
	long long res = 0;
	while (i){
		res *= 10;
		res += i%10;
		i /= 10;
	}


	return res;
}

long long pow(long long b, long long e){
	long long res = 1;
	for (int i = 0; i < e; i++){
		res *= b;
	}
	return res;
}

long long ones(int i){
	long long res = 1;

	return res;
}

long long basefor(int i){
	long long res = 10;

	for (int k = 3; k <= i; k++){
		long long d = 1;
		if (k % 2 == 0){
			d = pow(10, k/2) + ones(k/2-1)*9;
		}
		else
			d = pow(10, k/2) + ones(k/2)*9;
//		cout<<k<<" -> "<<d<<endl;
		res += d;
	}	
//	cout<<"basefor: "<<i<<" = "<<res<<endl;
	return res;
}

string toS(long long a){
	string cad = "";
	long long ax = a;
	while (a){
		long long diez = 10;
		int d = (a % diez);
		char k = '0'+d;
//		cout<<d<<" -> "<<k<<endl;
		cad = k+cad;
		a /= 10;
	}
//	cout<<ax<<" -> "<<cad<<endl;
	return cad;
}

long long toInt(string a, int i, int f){
	long long res = 0;
	while (i < f){
		res *= 10;
		res += (a[i]-'0');
		i++;
	}
//	cout<<a<<" to ->"<<res<<endl;
	return res;
}

long long fst(long long a){
	string num = toS(a);

	return toInt(num, 0, num.length()/2);
}

long long sec(long long a){
	string num = toS(a);
	return toInt(num, num.length()/2, num.length());
}

long long solve(long long i){
	long long res;
//	cout<<"solving "<<i<<endl;
	if (i > 20){
		res = basefor(tam(i)) + fst(i) + sec(i);
		if (fst(i) == 1)
			res--;

	}
	else
		res = i;

	return res;
}

int main(){
	int nTest;
	cin>>nTest;
	for(int test = 1; test <= nTest; test++){
		cin>>n;
		bool flag = false;
		if (n % 10 == 0){
			n--;
			flag = true;
		}

		cout<<"Case #"<<test<<": "<<solve(n) + (flag ? 1 : 0)<<endl;
	}
	return 0;
}