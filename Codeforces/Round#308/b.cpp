#include <iostream>
#include <cstring>

using namespace std;

int main(){
	long long n;

	cin>>n;

	long long l = 0;
	long long res = 0;	
	long long d = 0;
	long long k = 1;
	while(n > d*10+9){
		d = d*10+9;
		l++;

		//cout<<"d: "<<d<<" "<<l<<endl;
		res += (k*l*9);
		k*= 10;

	}
	n -= d;
	l++;

		//cout<<"d: "<<n<<" "<<l<<endl;
	res += (l*n);


	cout<<res<<endl;
	return 0;
}