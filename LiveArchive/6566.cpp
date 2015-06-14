#include <iostream>
#include <cmath>

using namespace std;
long long n;
bool isOn(long long bulb, long long t){

	if (t == n){
		return false;
	}
	else{
		bool tot = false;
		for (long long i = 1; i <= sqrt((long double)bulb) && i <= sqrt(t); i++){
			if (bulb % i == 0){
				tot = !tot;
				if (bulb / i <= t && i*i != bulb)
					tot = !tot;
			}
		}
		return tot;
	}
}

int main(){
	long long  t, b;
	int test = 0;
	while (cin>>n>>t>>b){
		test++;

		cout<<"Case "<<test<<": ";

		if (isOn(b, (t % n) ? t % n : n))
			cout<<"On"<<endl;
		else 
			cout<<"Off"<<endl;
	}
	return 0;
}