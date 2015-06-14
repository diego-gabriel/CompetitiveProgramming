#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

struct Person
{
	string name;
	int day, month, year;
	Person(){}
	void read(){
		cin>>name>>day>>month>>year;
	}
};

bool operator < (Person a, Person b){
	if (a.year == b.year)
		if (a.month == b.month)
			return a.day < b.day;
		else
			return a.month < b.month;
	else		
		return a.year < b.year;
}
bool operator > (Person a, Person b){
	return b < a;
}

int main(){

	int n;

	while (cin>>n){
		Person y, o;
		y.year = 9999999;
		y.day = 9999999;
		y.month = 9999999;

		o.year = 0;
		o.day = 0;
		o.month = 0;

		Person aPerson;

		for (int i = 0; i < n; i++){
			aPerson.read();

			if (aPerson < y)
				y = aPerson;
			if (aPerson > o)
				o = aPerson;
		}

		cout<<o.name<<endl;
		cout<<y.name<<endl;

	}
	return 0;
}