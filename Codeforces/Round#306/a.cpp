#include <iostream>

using namespace std;

int main(){
	string s;
	cin>>s;

	bool ba, ab;
	ba = ab = false;
	int ov = 0;
	for (int i = 0; i < s.length()-1; i++){
		if (s[i] == 'A' && s[i+1] == 'B'){
			if (i+2 < s.length() && s[i+2] == 'A'){
				ov++;
				i += 2;
			}
			else{
				ab = true;
				i++;
			}

		}
		else if(s[i] == 'B' && s[i+1] == 'A'){
			if (i+2 < s.length() && s[i+2] == 'B'){
				ov++;
				i += 2;
			} else{
				ba = true;
				i++;
			}
		}
	}

	if ((ab && ba) || ((ab || ba) && ov == 1) || ov > 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}