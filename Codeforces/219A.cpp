#include <iostream>
#include <cstring>

using namespace std;

string rep(char k, int i)
{
	string res = "";

	while (i)
	{
		res += k;
		i--;
	}
	//cout<<res<<endl;
	return res;
}

int main()
{
	int k;
	string cad;

	int freq[200];
	memset(freq, 0, sizeof(freq));
	cin>>k>>cad;

	for (int i = 0; i < cad.length(); i++)
	{
		freq[cad[i]]++;
	}	

	bool isK = true;
	string res = "";
	int tar = cad.length() / k;

	isK = tar*k == cad.length();

	if (isK)
	{
		for (char i = 'a'; i <= 'z'; i++)
		{
			isK = isK && (freq[i] >= k || freq[i] == 0) && freq[i] % k == 0;
			res += rep(i, freq[i] / k);
		}

	} 

	if (isK){
		cad = res;
		k--;
		while (k--)
		{
			res += cad;
		}
		cout<<res<<endl;	
	} 
	else cout<<-1<<endl;

	return 0;
}