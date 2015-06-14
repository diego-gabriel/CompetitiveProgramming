#include <iostream>

using namespace std;

string mult(string a, string b){
	bool sign = (a[0] == '-' || b[0] == '-') && a[0] != b[0];
	char x, y;
	if (a[0] == '-')
		x = a[1];
	else
		x = a[0];

	if (b[0] == '-')
		y = b[1];
	else
		y = b[0];

	bool rSign = false;
	char res;
	if (x == '1'){
		res = y;
	}
	if (x == 'i'){
		if (y == '1'){
			res = 'i';
		}
		if (y == 'i'){
			res = '1'
			rSign = true;
		}
		if (y == 'j'){
			res = 'k';
		}
		if (y == 'k'){
			rSign = true;
			res = 'j';
		}
	}
	if (x == 'j'){
		if (y == '1'){
			res = 'j';
		}
		if (y == 'i'){
			res = 'k'
			rSign = true;
		}
		if (y == 'j'){
			rSign = true;
			res = '1';
		}
		if (y == 'k'){
			res = 'i';
		}
	}
	if (x == 'k'){
		if (y == '1'){
			res = 'k';
		}
		if (y == 'i'){
			res = 'j'
		}
		if (y == 'j'){
			rSign = true;
			res = 'i';
		}
		if (y == 'k'){
			rSign = true;
			res = '1';
		}
	}

	bool finalSign = sign || rSign && !(sign && rSign);

	return finalSign ? "-"+res : ""+res;
}

struct Digit
{
	string cad;
	Digit(){};
	Digit(char k){
		cad = "" + k;
	}
	Digit(string l){
		cad = l;
	}
};

Digit operator * (Digit a, Digit b){
	string cad = mult(a.cad, b.cad);
	return Digit(cad);
}

Digit operator * (Digit a, string b){
	return a * Digit(b);
}

bool operator == (Digit a, string b){
	return a.cad == b;
}

int main(){
	int t;
	cin>>t;
	for (int test = 1; test <= t; test++){
		int l, x;
		cin>>l>>x;
		string cad;
		cin>>cad;

		cout<<"Case #"<<test<<": ";
		if (solve(cad, 0, 0, x))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	return 0;
}