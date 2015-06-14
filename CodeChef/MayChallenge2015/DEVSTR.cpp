#include <iostream>
#include <cstring>

using namespace std;

int diff(bool k, string &s){
	int res = 0;
	int n = s.length();
	for (int i = 0; i < n; i++){
		if (k && s[i] == '0')
			res++;
		if (!k && s[i] == '1')
			res++;

		k = !k;
	}

	return res;
}

void build(bool k, int n){
	for(int i = 0; i < n; i++){
		if (k)
			cout<<1;
		else
			cout<<0;

		k = !k;
	}

	cout<<endl;
}

char r[100005];
int last;

int print(int size, char car, int k){

	int res = 0;
	for (int i = last; i < last + size; i++){
		r[i] = car;
	}

	car = car == '0' ? '1' : '0';

	for (int i = last+k; i < last+size; i += k){
		if (i == last+size-1)
			r[i-1] = car;
		else
			r[i] = car;
		i++;
		res++;
	}

	last += size;
	return res;
}

int main(){
	int t;
	cin>>t;

	while (t--){
		last = 0;
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;

		if (k == 1){

			int d1 = diff(true, s);
			int d2 = diff(false, s);

			if (d1 < d2){
				cout<<d1<<endl;
				build(true, n);
			}
			else{
				cout<<d2<<endl;
				build(false, n);
			}
		} else{

			int size = 1;
			char c = s[0];
			int res = 0;
			for (int i = 1; i < n; i++){
				if (s[i] == c)
					size++;
				else{

					res += print(size, c, k);

					c = s[i];
					size = 1;
				}
			}
			res += print(size, c, k);

			cout<<res<<endl;
			for (int i = 0; i < n; i++)
				cout<<r[i];
			cout<<endl;
		}
	}
	return 0;
}