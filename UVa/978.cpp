#include <iostream>
#include <set>
#include <vector>

using namespace std;

int ides;

struct Lemming
{
	int power;
	int id;
	Lemming(){};
	Lemming(int p){
		power = p;
		id = ides;
		ides++;
	}
	void attack(int p){
		power -= p;
	}
};

bool operator < (Lemming a, Lemming b){
	if (a.power == b.power)
		return a.id < b.id;
	return a.power > b.power;
}

int main(){
	int n;
	cin>>n;
	while (n--){

		int b, ng, nb;
		set<Lemming> green, blue;

		cin>>b>>ng>>nb;
		int p;
		ides = 0;
		for(int i = 0; i < ng; i++){
			cin>>p;
			green.insert(Lemming(p));
		}
		for(int i = 0; i < nb; i++){
			cin>>p;
			blue.insert(Lemming(p));
		}

		while (!green.empty() && !blue.empty()){
			set<Lemming> :: iterator bt, gt;
			vector<Lemming> dgreen, dblue;


			for (int i = 0; i < b; i++){
				if (blue.empty() || green.empty())
					continue;

				Lemming aBlue, aGreen;

				aBlue = *(blue.begin());
				blue.erase(aBlue);

				aGreen = *(green.begin());
				green.erase(aGreen);

				if (aBlue.power > aGreen.power){
					aBlue.attack(aGreen.power);
					dblue.push_back(aBlue);
				}
				else
					if (aGreen.power > aBlue.power){
						aGreen.attack(aBlue.power);
						dgreen.push_back(aGreen);
					}
			}

			for (int i = 0; i < dgreen.size(); i++){
				green.insert(dgreen[i]);
			}
			for (int i = 0; i < dblue.size(); i++){
				blue.insert(dblue[i]);
			}
		}

		if (green.empty() && blue.empty()){
			cout<<"green and blue died"<<endl;
		}
		else{
			set<Lemming>:: iterator bt, et;
			if (green.empty()){
				cout<<"blue wins"<<endl;
				bt = blue.begin();
				et = blue.end();
			}
			else{
				cout<<"green wins"<<endl;
				bt = green.begin();
				et = green.end();
			}

			while (bt != et){
				cout<<bt->power<<endl;
				bt++;
			}
		}
		if (n)
			cout<<endl;
	}
	return 0;
}