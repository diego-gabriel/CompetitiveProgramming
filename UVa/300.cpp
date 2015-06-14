#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;
map <string, int> a;
string b[20];

void init(){
	a["pop"] = 0;
	a["no"] = 1;
	a["zip"] = 2;
	a["zotz"] = 3;
	a["tzec"] = 4;
	a["xul"] = 5;
	a["yoxkin"] = 6;
	a["mol"] = 7;
	a["chen"] = 8;
	a["yax"] = 9;
	a["zac"] = 10;
	a["ceh"] = 11;
	a["mac"] = 12;
	a["kankin"] = 13;
	a["muan"] = 14;
	a["pax"] = 15;
	a["koyab"] = 16;
	a["cumhu"] = 17;
	a["uayet"] = 18;

	b[0] = "imix";
	b[1] = "ik";
	b[2] = "akbal";
	b[3] = "kan";
	b[4] = "chicchan";
	b[5] = "cimi";
	b[6] = "manik";
	b[7] = "lamat";
	b[8] = "muluk";
	b[9] = "ok";
	b[10] = "chuen";
	b[11] = "eb";
	b[12] = "ben";
	b[13] = "ix";
	b[14] = "mem";
	b[15] = "cib";
	b[16] = "caban";
	b[17] = "eznab";
	b[18] = "canac";
	b[19] = "ahau";
}

struct Haab
{
	int day, year;
	string month;

	Haab(){
		day = year = 0;
		month = "";
	}

	void read(){
		scanf("%d.", &day);
		cin>>month>>year;
	}

	int numberDate(){
		int res = year * 365 + day + a[month]*20;

		return res;
	}

};

struct Tzolkin
{
	int day, year;
	string month;

	Tzolkin(){
		day = year = 0;
		month = "";
	}

	Tzolkin(Haab y){
		int nDays = y.numberDate();
		year = nDays / 260;
		day = (nDays % 13) + 1;
		month = b[nDays % 20];
	}	

	void print(){
		cout<<day<<" "<<month<<" "<<year<<endl;
	}
};

int main(){
	int n;
	init();
	cin>>n;
	Haab years[n];

	for (int i = 0; i < n; i++)
		years[i].read();

	cout<<n<<endl;
	for (int i = 0; i < n; i++){
		Tzolkin year = Tzolkin(years[i]);
		year.print();
	}
	
	return 0;
}