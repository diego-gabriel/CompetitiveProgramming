#include <iostream>
#include <set>
using namespace std;

set<long long> valid;

void init(long long n, long long i){
	if (n <= 1000000000){
		valid.insert(n);
		init(n + 6*i, i+1);
	}
	
}


int main(){
	long long n;

	init(1, 1);
	while (cin>>n && n != -1){
		if (valid.find(n) == valid.end())
			cout<<"N"<<endl;
		else
			cout<<"Y"<<endl;
	}
	return 0;
}