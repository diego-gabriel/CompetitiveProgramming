#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int test;
	cin>>test;
	int n = 0;
	while(test--){
		n++;
		printf("Case #%d: ", n);

		int day, month, year;
		int d, m, y;

		scanf("%d/%d/%d", &day, &month, &year);
		scanf("%d/%d/%d", &d, &m, &y);
		int age = year - y;
		if (m > month || (month == m && d > day))
			age--;

		if (age > 130)
			cout<<"Check birth date"<<endl;
		else
		if (age < 0)
			cout<<"Invalid birth date"<<endl;
		else cout<<age<<endl;
	}
	return 0;
}