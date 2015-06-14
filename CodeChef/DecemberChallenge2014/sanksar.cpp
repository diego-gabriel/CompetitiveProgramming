#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool orden(long long a, long long b){
	return a > b;
}

vector <long long> s;
long long target;
bool solve(int mask, int k, int suma){
	if ()

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		s.clear();
		vector <long long> :: reverse_iterator it;
		long long v, suma;
		suma = 0;
		for (int i = 0; i < n; i++){
			cin>>v;
			if (v)
				s.insert(v); 
			suma += v;
		}

		sort(s.begin(), s.end(), orden);

		if (suma % k == 0)
		{
			target = suma / k;
			if (solve((1<<n)-1, k))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}	
		else
			cout<<"no"<<endl;


	}
	return 0;
}