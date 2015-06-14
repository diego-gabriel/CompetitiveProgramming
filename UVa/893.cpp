#include <iostream>

using namespace std;

int passed[13];

void init(){
	passed[1] = 0;
	passed[2] = passed[1] + 31;
	passed[3] = passed[2] + 28;
	passed[4] = passed[3] + 31;
	passed[5] = passed[4] + 10;
	passed[6] = passed[5] + 31;
	passed[7] = passed[6] + 30;
	passed[8] = passed[7] + 31;
	passed[9] = passed[8] + 31;
	passed[10] = passed[9] + 30;
	passed[11] = passed[10] + 31;
	passed[12] = passed[11] + 30;
}

int numOfBi(int year){
	int bi = year / 4;
	bi -= (year/100);
	bi += (year/400);
	return bi;
}

struct Fecha
{
	int day, month, year;

	Fecha(){
		day = month = year = 0;
	}

	Fecha(int nDays){
		year = 
	}

	void print(){
		cout<<day<<" "<<month<<" "<<year<<endl;
	}
};

int nOfDays(int day, int month, int year){
	int res = year*365;
	res += numOfBi(year);
	res += passed[month];
	res += day;
	if (month <= 2)
		res--;
	return res;
}

int main(){
	int n, d, m, y;

	while (cin>>n>>d>>m>>y && (n || d || m || y)){
		Fecha res = Fecha(nOfDays(d, m, y) + n);
		res.print();
	}
	return 0;
}