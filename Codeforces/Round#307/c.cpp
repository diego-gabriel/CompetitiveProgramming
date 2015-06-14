#include <iostream>

using namespace std;

long long a[100000+5];
long long b[100000+5];
int n, m;

//copy array a and return last non zero index;
int copy(){
	int res = 0;
	for (int i = 1; i <= n; i++){
		b[i] = a[i];
		if (a[i] != 0)
			res = i;
	}
	return res;
}

bool check(long long t){
	bool res = true;
	int last = copy();
	
//	cout<<"current time: "<<t<<endl;
//	cout<<"last non zero: "<<last<<endl;

	if (t < last)
		res = false;
	else {
		long long ct = t;
		long long rem;
		for (int i = 0; i < m && last > 0; i++){
			ct = t;
			//time wasted going to last pile
			ct -= last;
			while (last > 0 && ct > 0){

			//	cout<<ct<<" seconds remain..."<<endl;
				rem = min(b[last], ct);
				b[last] -= rem;
				ct -= rem;

				while (last > 0 && b[last] == 0)
					last--;
			}
		}
	}

	//cout<<"with time: "<<t<<" retuned: "<<last<<endl;
	return last == 0;
}

int main(){

	cin>>n>>m;

	long long begin, end;
	begin = end = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		end += a[i];
	}

	end += (n+5);

	while (end-begin > 1){
	//cout<<"begin: "<<begin<<" end: "<<end<<endl;
		long long mid = (begin + end) / 2;
		if (check(mid)){
			end = mid;
		} else {
			begin = mid;
		}
	}

	cout<<end<<endl;

	return 0;
}