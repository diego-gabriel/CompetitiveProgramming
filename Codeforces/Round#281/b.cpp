#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector <long long> sa, sb;
	long long n;
	cin>>n;
	long long p, ta, tb;
	ta = tb = 0;
	long long last;
	for (long long i = 0; i < n; i++){
		cin>>p;
		if (p > 0){
			ta += p;
			sa.push_back(p);
			last = 1;
		}
		else{
			tb -= p;
			sb.push_back(-p);
			last = 2;
		}
	}

	bool f;
	if (ta > tb)
		cout<<"first"<<endl;
	else
	if (tb > ta)
		cout<<"second"<<endl;
	else{
		if (sa > sb)
			cout<<"first"<<endl;
		else
		if (sb > sa)
			cout<<"second"<<endl;
		else{
			if (last == 1)
				cout<<"first"<<endl;
			else
				cout<<"second"<<endl;
		}
	}
	return 0;
}