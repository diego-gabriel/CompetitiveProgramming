#include <iostream>

using namespace std;

#define ANGELA "Angela gana"
#define EMPATE "Empate"
#define BERNARDO "Bernardo gana"

int main(){

	int nTest;
	cin>>nTest;

	while (nTest--){
		int ang, ber, n;
		ang = ber = 0;
		string cad;
		cin>>n;
		cin>>cad;

		for (int i = 0; i < cad.length(); i+=2){
			char a, b;
			a = cad[i];
			b = cad[i+1];

			if (a == 'T'){
				if (b == 'I')
					ber++;
				if (b == 'A')
					ang++;
			}

			if (a == 'I'){
				if (b == 'T')
					ang++;
				if (b == 'A')
					ber++;
			}

			if (a == 'A'){
				if (b == 'I')
					ang++;
				if (b == 'T')
					ber++;
			}
		}

		if (ang == ber)
			cout<<EMPATE<<endl;
		if (ang > ber)
			cout<<ANGELA<<endl;
		if (ber > ang)
			cout<<BERNARDO<<endl;
	}
	return 0;
}