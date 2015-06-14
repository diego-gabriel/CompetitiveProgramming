#include <iostream>
#include <cstring>

using namespace std;

int n;

void add(string &p){
	char k = '1';
	for (int i = n-1; i >= 0; i--){
		if (p[i] == '1'){
			if (k == '1'){
				p[i] = '0';
			}
		} else {
			if (k == '1'){
				p[i] = '1';
				k = 0;
			}
		}
	}

}

int findones(string &a, string &b){
	for (int i = 0; i < n; i++){
		if (a[i] == b[i] && a[i] == '1')
			return i;
	}
	return -1;
}

int findzero(string &a, string &b, int init){
	for (int i = init; i >= 0; i--){
		if (a[i] == b[i] && a[i] == '0')
			return i;
	}
	return -1;
}

bool inter(string &a, string &b){
	for (int i = 0; i < n; i++){
		if (a[i] == b[i])
			return false;
	}
	return true;
}

void toZero(string &a){
	for(int i = 0; i < n; i++){
		a[i] = '0';
	}
}



int main(){
	string p, q;
	cin>>n>>p>>q;

	//si son intercalados
	if (inter(p, q)){
		add(p);
		toZero(q);
		
	} else {
		// there must be 00 or 11
		int pone = findones(p, q);
		if (pone != -1){ // here is a 11
			int zero = findzero(p, q, pone);
			//there is no 00 <-
			if (zero == -1) {
				add(p);
				toZero(q);
			} else { // there is a 00 <-
				q[zero] = '1';
				for (int i = zero+1; i < n; i++)
					q[i] = '0';
			}
		} else {
			//there must be a 00
			int zero = findzero(p, q, n-1); //so this is not -1

			q[zero] = '1';
			for (int i = zero+1; i < n; i++)
				q[i] = '0';
		}
	}

	cout<<p<<endl<<q<<endl;

	return 0;
}