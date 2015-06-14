#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int cant = 'z'-'a'+1;

struct Word
{
	int count['z'-'a'+1];

	Word(){
	}
	Word(string cad){

		for(int i = 0; i < 'z'-'a'+1; i++)
			count[i] = 0;
		for(int i = 0, n = cad.length(); i < n; i++){
			count[cad[i]-'a']++;
		}

	/*for(int i = 0; i < cant; i++){
			cout<<(char)(i+'a')<<" -> "<<count[i]<<endl;
		}*/
	}

	void multiplyAll(int x){
		for(int i = 0; i < cant; i++){
			count[i] *= x;
		}
	}

	void substract(Word b){
		for(int i = 0; i < cant; i++){
			count[i] -= b.count[i];
		}	
	}

	bool allPositive(){
		for(int i = 0; i < cant; i++){
			if (count[i] < 0)
				return false;
		}
		return true;
	}

	void print(){
		for(int i = 0; i < cant; i++){

			while(count[i]--){
				cout<<(char)(i+'a');
			}
		}

		cout<<endl;

	}

	int times(Word x){
		int res = 0x7fffffff;

		for(int i = 0; i < cant; i++){
			if (x.count[i] == 0)
				continue;
			res = min(res, count[i]/x.count[i]);
		}

		return res;
	}

	bool fit(Word x){

		for(int i = 0; i < cant; i++){
			if (x.count[i] < count[i])
				return false;
		}
		return true;	
	}
};

Word operator * (Word a, int b){
	a.multiplyAll(b);
	return a;
}

Word operator - (Word a, Word b){
	a.substract(b);
	return a;
}

int main(){
	string wa, wb, wc;
	cin>>wa>>wb>>wc;
	Word a = Word(wa);
	Word b = Word(wb);
	Word c = Word(wc);

	int m = 0;
	int best = 0;
	int bestb;
	int cc;
	while ((b*m).fit(a)){
		cc = (a - (b*m)).times(c);

		if(m+cc > best){
			best = m+cc;
			bestb = m;
		}
		m++; 
	}

	int cm = bestb;
	cc = best - bestb;
	int x, y;
	x = cm;
	y = cc;
	while(cm--)
		cout<<wb;
	while(cc--)
		cout<<wc;



	((a-(b*x))-(c*y)).print();

	return 0;
}