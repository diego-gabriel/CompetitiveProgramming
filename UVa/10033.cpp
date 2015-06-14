#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string ram[1001];
int reg[11];

int to_i(string cad){
	int res = 0;
	for (int i = 0; i < cad.length(); i++){
		res *= 10;
		res = res + cad[i]-'0';
	}
	return res;
}

string to_s(int n){
	string res = "";
	while (n){
		char k = (n % 10) + '0';
		n /= 10;
		res = res + k;
	}
	return res;
}

int main(){
	int test;
	scanf("%d", &test);
	string cad;
    char instr[5];
	fgets(instr, sizeof(instr), stdin);
	fgets(instr, sizeof(instr), stdin);

	while (test--){
		memset(reg, false, sizeof(reg));
		int i = 0;
		while (fgets(instr, sizeof(instr), stdin) != NULL){
			if (instr[0] == '\n') break;
 
			ram[i][0] = instr[0];
			ram[i][1] = instr[1];
			ram[i][2] = instr[2];
			cout<<ram[i]<<endl;
			i++;
		}
		int total = i;
		int res = 0;
		i = 0;
		while (true){
			res++;
			if (ram[i] == "100")
				break;
			int o, d, n;
			o = ram[i][0]-'0';
			d = ram[i][1]-'0';
			n = ram[i][2]-'0';

			switch(o){
				case 2:{
					reg[d] = n;
				} break;
				case 3:{
					reg[d] += n;
					reg[d] %= 1000;
				} break;
				case 4:{
					reg[d] *= n;
					reg[d] %= 1000;
				} break;
				case 5:{
					reg[d] = reg[n];
				} break;
				case 6:{
					reg[d] += reg[n];
					reg[d] %= 1000;
				} break;
				case 7:{
					reg[d] *= reg[n];
					reg[d] %= 1000;
				} break;
				case 8:{
					reg[d] = to_i(ram[reg[n]]);
				} break;
				case 9:{	
					ram[reg[n]] = to_s(reg[d]);
				} break;
				case 0:{
					if (reg[n] != 0){
						i = reg[d];
						i--;
					}
				} break;
			}
			i++;
		}
		cout<<res<<endl;
		if (test) cout<<endl;
	}
	return 0;
}