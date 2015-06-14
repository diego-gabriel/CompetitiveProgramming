#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

map <string, float> timeZone;

void init(){
	timeZone["UTC"] = 0.0;
	timeZone["GMT"] = 0.0;
	timeZone["BST"] = 1.0;
	timeZone["IST"] = 1.0;
	timeZone["WET"] = 0.0;
	timeZone["WEST"] = 1.0;
	timeZone["CET"] = 1.0;
	timeZone["CEST"] = 2.0;
	timeZone["EET"] = 2.0;
	timeZone["EEST"] = 3.0;
	timeZone["MSK"] = 3.0;
	timeZone["MSD"] = 4.0;
	timeZone["AST"] = -4.0;
	timeZone["ADT"] = -3.0;
	timeZone["NST"] = -3.5;
	timeZone["NDT"] = -2.5;
	timeZone["EST"] = -5.0;
	timeZone["EDT"] = -4.0;
	timeZone["CST"] = -6.0;
	timeZone["CDT"] = -5.0;
	timeZone["MST"] = -7.0;
	timeZone["MDT"] = -6.0;
	timeZone["PST"] = -8.0;
	timeZone["PDT"] = -7.0;
	timeZone["HST"] = -10.0;
	timeZone["AKST"] = -9.0;
	timeZone["AKDT"] = -8.0;
	timeZone["AEST"] = 10.0;
	timeZone["AEDT"] = 11.0;
	timeZone["ACST"] = 9.5;
	timeZone["ACDT"] = 10.5;
	timeZone["AWST"] = 8.0;
}

struct Hour
{
	int hours, minutes;
	char per;
	float zone;

	Hour(){
	}

	void print(){
		if (hours == 0 && minutes == 0){
			cout<<"midnight"<<endl;
		} else
		if (hours == 12 && minutes == 0){
			cout<<"noon"<<endl;
		} else {
			cout<<(hours%12 == 0 ? 12 : hours%12)<<':';
			printf("%02d ", minutes);
			if (hours < 12)
				cout<<"a.m."<<endl;
			else
				cout<<"p.m."<<endl;
		}
	}

	void read(){
		string t;
		cin>>t;
		if (t == "noon"){
			hours = 12;
			minutes = 0;
			per = 'a';
		}
		else
		if (t == "midnight"){
			hours = 0;
			minutes = 0;
			per = 'p';
		}
		else{
			hours = minutes = 0;
		//	cout<<t<<endl; 
			if (t.length() == 5){
				hours = (t[0]-'0')*10 + (t[1]-'0');
				minutes = (t[3]-'0')*10 + (t[4]-'0');
			} else {
				hours = (t[0]-'0');
				minutes = (t[2]-'0')*10 + (t[3]-'0');
			}

			cin>>t;

			per = t[0];
			if (per == 'p' && hours != 12)
				hours += 12;
			if (per == 'a' && hours == 12)
				hours = 0;
			hours = hours % 24;
		}


		cin>>t;
		zone = timeZone[t];

		cin>>t;
		zone = timeZone[t] - zone;

		//cout<<endl<<"diff: "<<zone<<endl;
		//cout<<"hour: "<<hours<<endl<<"minutes: "<<minutes<<endl;

		hours += (int)zone;
		minutes += ((zone - ((int)zone))*60);

		if (minutes < 0){
			minutes += 60;
			hours--;
		}

		hours += (minutes/60);
		minutes = minutes % 60;

		hours = (24 + hours) % 24;

		print();
	}
};

int main(){
	init();
	int n;
	cin>>n;
	Hour h;
	while (n--){
		h.read();
	}
	return 0;
}