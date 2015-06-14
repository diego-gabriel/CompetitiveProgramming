#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	while (n--){
		int l;
		cin>>l;
		char a, b;
		int angela, bernardo;
		angela = bernardo = 0;
		for (int i = 0; i < l; i++){
			cin>>a>>b;
			if (a == 'I'){
				if (b == 'T')
					angela++;
				if (b == 'A')
					bernardo++;
			}
			if (a == 'T'){
				if (b == 'A')
					angela++;
				if (b == 'I')
					bernardo++;
			}
			if (a == 'A'){
				if (b == 'T')
					bernardo++;
				if (b == 'I')
					angela++;
			}
		}
		if (angela > bernardo)
			cout<<"Angela gana"<<endl;
		else if (bernardo > angela)
			cout<<"Bernardo gana"<<endl;
		else
			cout<<"Empate"<<endl;
	}
	return 0;
}