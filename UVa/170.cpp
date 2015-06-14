#include <iostream>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

map <char, stack <string> > game;

void play (string card, int t){
	char deck = card[0];
	if (game[deck].empty()){
		if (t < 10) cout<<0;
		cout<<t<<","<<card<<endl;
	}
	else{
		card = game[deck].top();
		game[deck].pop();
		play(card, t+1);
	}
}

int main(){

	string cad;
	bool cont = true;

	while (cont){
		game.clear();
		stack <string> deck;
		cin>>cad;
		cont = cad != "#";
		if (!cont) break;
		deck.push(cad);

		for (int i = 1; i < 52; i++){
			cin>>cad;
			deck.push(cad);
		}

		for (int i = 0; i < 4 && cont; i++){
			cad = deck.top();
			deck.pop();
		
			game['A'].push(cad);
			for (int j = 2; j <= 9 && cont; j++){
				cad = deck.top();
				deck.pop();
				game['0'+j].push(cad);
			}	

			cad = deck.top();
			deck.pop();
			game['T'].push(cad);
			cad = deck.top();
			deck.pop();
			game['J'].push(cad);
			cad = deck.top();
			deck.pop();
			game['Q'].push(cad);
			cad = deck.top();
			deck.pop();
			game['K'].push(cad);

		}
		if (!cont) break;
		string card = game['K'].top();
		game['K'].pop();
		play(card, 1);
	}


	return 0;
}