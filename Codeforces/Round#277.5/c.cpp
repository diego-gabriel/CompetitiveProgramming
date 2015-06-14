#include <iostream>

using namespace std;

void lesss(int m, int s){
	if (s == 0)
		cout<<"0"<<endl;
	else{
		if ((m-1)*9+1 >= s){
			cout<<1;
			s--;
			m--;
		}
		while(m){
			if ((m-1)*9 >= s){
				cout<<0;
			}
			else{
				cout<<s-(9*(m-1));
				s -= s-(9*(m-1));
			}
			m--;
		}
	}
}

void best(int m, int s){

	while(m){
		if (s > 9){
			cout<<9;
			s -= 9;
		}
		else{
			cout<<s;
			s = 0;
		}
		m--;
	}
}

int main(){
	int m, s;
	cin>>m>>s;

	if (s == 0 && m != 1){
		cout<<"-1 -1"<<endl;
	}
	else
	if (s > m*9){
		cout<<"-1 -1"<<endl;
	}
	else{
		lesss(m, s);
		cout<<" ";
		best(m, s);
		cout<<endl;
	}
	return 0;
}