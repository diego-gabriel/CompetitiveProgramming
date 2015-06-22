#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

	int s, k;
	cin>>s>>k;
	int f[1000000];
	f[0] = 1;
	f[1] = 1;	
	int n;

	for(n = 2; n < k && f[n-1] < s; n++)
		f[n] = 2*f[n-1];

	n--;
	stack<int> res;
	while (f[n] < s){
		n++;
		f[n] = 2*f[n-1] - (n-k-1 < 0 ? 0 :f[n-k-1]);
		//cout<<"f("<<n<<") = "<<f[n]<<endl;
	}


		while (s){
			if (f[n] <= s){
				s -= f[n];
				res.push(f[n]);
			}
			n--;
		}
		res.push(0);
		cout<<res.size()<<endl;
		cout<<res.top();
		res.pop();
		while (!res.empty()){
			cout<<" "<<res.top();
			res.pop();
		}
		cout<<endl;

	
	return 0;
}