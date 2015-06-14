#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>

using namespace std;


struct Info
{
	char k;
	int n;
	Info(){};
	Info(char a, int b){
		k = a;
		n = b;
	}
};

bool operator < (Info a, Info b){
	if (a.n == b.n)
		return a.k < b.k;
	return a.n > b.n;
}

int count[300];

int main(){
	int n;
	cin>>n;
	while (n--){
		string cad;
		cin>>cad;
		for (int i = 0; i < 300; i++){
			count[i] = 0;
		}

		for (int i = 0; i < cad.length(); i++){
			count[cad[i]]++;
		}

		int tot = cad.length();
		int mp = (tot+1)/2;

		bool res = true;

		set<Info> inf;
		for (int i = 0; i < 300; i++){
			if (count[i] > mp){
				res = false;
			}
			if (count[i] > 0)
				inf.insert(Info((char)i, count[i]));
		}

		char last = ' ';
		int i = 0;
		if (res){
			while (tot--){
				Info f = *(inf.begin());
				Info s;
				inf.erase(inf.begin());
				//cout<<"last: "<<last<<endl;
				//cout<<"first : "<<f.k<<" #"<<f.n<<endl;
				if (f.k == last){
					s = *(inf.begin());
					inf.erase(inf.begin());
					cad[i] = s.k;
					s.n--;
					last = s.k;
					if (s.n > 0)
						inf.insert(s);
				}
				else{
					cad[i] = f.k;
					f.n--;
					last = f.k;
				}

				if (f.n > 0)
					inf.insert(f);
				i++;
			}
			cout<<cad<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}