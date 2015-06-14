#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

struct carta {
	int valor;
	string palo;

	carta(){}

	carta(int v, string p){
		valor = v;
		palo = p;
	}

};

int main(){

	int s1, s2, s3;
	string p1, p2, p3;
	vector<carta> cartas;

	while (cin>>s1>>p1>>s2>>p2>>s3>>p3 && (s1 != -1 && s2 != -1 && s3 != -1) && (p1 != "*" && p2 != "*" && p3 != "*")){
		
	}
}