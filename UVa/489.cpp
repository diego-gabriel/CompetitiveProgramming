#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main(){
	int n;
	while (cin>>n && n != -1){

		string cad;
		string seq;

		cin>>cad>>seq;

		set<char> toGuess, guessed;
		set<char> :: iterator it;
		int lives = 7;

		for (int i = 0; i < cad.length(); i++){
			toGuess.insert(cad[i]);
		}

		for (int i = 0; i < seq.length() && lives > 0 && toGuess.size() > 0; i++){
			char k = seq[i];
			if (toGuess.find(k) == toGuess.end()){
				lives--;
			}
			else
				toGuess.erase(k);
		}

		cout<<"Round "<<n<<endl;
		if (lives <= 0){
			cout<<"You lose."<<endl;
		}
		else
			if (toGuess.empty()){
				cout<<"You win."<<endl;
			}
			else
				cout<<"You chickened out."<<endl;
	}
	return 0;
}