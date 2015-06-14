#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Person
{
	int in, out;
	string name;
	Person(){};
	Person(string n){
		in = out = 0;
		name = n;
	}

	int gift(int total, int n){
		int res = 0;
		if (n){
			out = total;
			in += total % n;
			res = total/n;
		}
		else
		{
			out = total;
			in += total;
		}
		return res;
	}

	void receive(int n){
		in += n;
	}

	void show(){
		cout<<name<<" "<<(in-out)<<endl;
	}
};

int main(){
	int n;
	bool fst = true;
	while (cin>>n){
		if (!fst)
			cout<<endl;
		string names[n], name, nameTo;
		int cant, np;
		map <string, Person> person;
		for (int i = 0; i < n; i++){
			cin>>names[i];
			person[names[i]] = Person(names[i]);
		}

		for (int i = 0; i < n; i++){
			cin>>name>>cant>>np;
			cant = person[name].gift(cant, np);
			for (int j = 0; j < np; j++){
				cin>>nameTo;
				person[nameTo].receive(cant);
			}
		}

		for (int i = 0; i < n; i++){
			person[names[i]].show();
		}
		fst = false;
	}

	return 0;
}