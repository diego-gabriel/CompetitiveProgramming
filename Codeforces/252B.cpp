#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	if (n > 2){
		int last, curr;
		cin>>last;
		int a, b;
		bool ok = false;
		for (int i = 1; i < n; i++){
			cin>>curr;

			if (!ok && curr != last){
				a = i;
				b = i+1;
				ok = true;
			}
			last = curr;
		}

		if (ok)
			cout<<a<<" "<<b<<endl;
		else
			cout<<-1<<endl;
	} else {
		int a;
		for (int i = 0; i < n; i++){
			cin>>a;
		}
		cout<<-1<<endl;
	}

	return 0;
}