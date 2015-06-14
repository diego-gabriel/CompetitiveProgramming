#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 1000005

string cad;
int to[500];
int a[MAX];
long long memo[MAX][4][4];
long long acum[MAX][4];
long long l, r;

void mapp(){
	for (long long i = 0; i < cad.length(); i++){
		a[i+1] = to[cad[i]];
	}
}

void count(long long start, long long end){
	long long total = 0;
	long long cantS = 0;
	memo[0][start][end] = 0;
	for (long long i = 1; i <= cad.length(); i++){
		if (a[i] == start)
			cantS++;
		if (a[i] == end)
			total += cantS;
		memo[i][start][end] = total;
	}
}

void count(long long number){
	long long total = 0;

	acum[0][number] = 0;
	for (long long i = 1; i <= cad.length(); i++){
		if (a[i] == number)
			total++;
		acum[i][number] = total;
	}
}


void init(){
	to['c'] = 0;
	to['h'] = 1;
	to['e'] = 2;
	to['f'] = 3;
	mapp();
	memset(memo[0], 0, sizeof(memo[0]));
	count(0, 1);
	count(0, 2);
	count(0, 3);
	count(1, 0);
	count(1, 2);
	count(1, 3);
	count(2, 0);
	count(2, 1);
	count(2, 3);
	count(3, 0);
	count(3, 1);
	count(3, 2);

	count(0);
	count(1);
	count(2);
	count(3);
}

long long cant(long long from, long long to, long long item){
	return acum[to][item] - acum[from-1][item];
}

long long solve(long long begin, long long end){
	//cout<<begin<<" -> "<<end<<endl;
	/*cout<<"memo[end][l][r]     = "<<memo[end][l][r]<<endl;
	cout<<"memo[begin-1][l][r] = "<<memo[begin-1][l][r]<<endl;
	cout<<"cant(1, begin-1, l) = "<<cant(1, begin-1, l)<<endl;
	cout<<"cant(begin, end, r) = "<<cant(begin, end, r)<<endl;*/
	return memo[end][l][r] - memo[begin-1][l][r] - (cant(1, begin-1, l) * cant(begin, end, r));
}

int main(){
	cin>>cad;

	init();
	//cout<<"done"<<endl;
	long long n;
	scanf("%lld\n", &n);
	for (long long i = 0; i < n; i++){
		long long s, e;
		char left, right;
		scanf("%c %c %lld %lld\n", &left, &right, &s, &e);
		l = to[left];
		r = to[right];
		//cout<<"read: "<<left<<" "<<right<<endl;
		printf("%lld\n", solve(s, e));
	}
	return 0;
}