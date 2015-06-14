#include <iostream>

using namespace std;

struct Pos
{
	int before, after;
	Pos(){}
}cards[17];

int main(){

	int test;
	cin>>test;
	for (int nTest = 1; nTest <= test; nTest++){
		int before, after, card;
		cin>>before;
		
		for (int row = 1; row <= 4; row++){
			
			for (int i = 0; i < 4; i++){
				cin>>card;
				cards[card].before = row;
			}
		}

		cin>>after;
		
		for (int row = 1; row <= 4; row++){
			
			for (int i = 0; i < 4; i++){
				cin>>card;
				cards[card].after = row;
			}
		}

		bool match = false;
		bool ok = true;
		int res;
		for (int i = 1; i <= 16 && ok; i++){
			if (cards[i].before == before && cards[i].after == after){
				if (!match){
					match = true;
					res = i;
				}
				else
					ok = false;
			}
		}
		cout<<"Case #"<<nTest<<": ";
		if (match && ok)
			cout<<res<<endl;
		else
			if (match && !ok)
				cout<<"Bad magician!"<<endl;
			else
				cout<<"Volunteer cheated!"<<endl;
	}

	return 0;
}