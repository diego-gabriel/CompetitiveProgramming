#include <iostream>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <cstdio>

using namespace std;

void toLowercase(string &cad)
{
	for (int i = 0; i < cad.length(); i++)
		cad[i] = tolower(cad[i]);
}

vector <string> split(string cad)
{
	vector <string> res;
	string pal = "";
	char k;
	for (int i = 0; i < cad.length(); i++)
	{
		k = cad[i];
		if (islower(k) || isdigit(k))
		{
			pal = pal + k;
		}
		else
		{
			if (pal != "")
			{
				//cout<<"new pal = "<<pal<<endl;
				res.push_back(pal);
			}
			pal = "";
		}
	}

	if (pal != "")
	{
		res.push_back(pal);
	}
	pal = "";
	return res;
}

int main()
{
	string cad1, cad2;
	int nTest = 0;
	while (getline(cin, cad1) && getline(cin, cad2))
	{
		nTest++;
		//toLowercase(cad1);
		//toLowercase(cad2);

		vector <string> pal1 = split(cad1);
		vector <string> pal2 = split(cad2);

		if (cad1.size() == 0 || cad2.size() == 0)
		{
			printf("%2d. Blank!\n", nTest);
		}
		else
		{
			int lcs[pal1.size() + 1][pal2.size() + 1];
			int res = 0;

			for (int i = 0; i < pal1.size()+1; i++)
				lcs[i][0] = 0;
			for (int i = 0; i < pal2.size()+1; i++)
				lcs[0][i] = 0;

			for (int i = 0; i < pal1.size(); i++)
			{
				for (int j = 0; j < pal2.size(); j++)
				{
					if (pal1[i] == pal2[j])
						lcs[i+1][j+1] = lcs[i][j] + 1;
					else
						lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
				}
			}



			printf("%2d. Length of longest match: %d\n", nTest, lcs[pal1.size()][pal2.size()]);
		}
	}

	//cout<<"input read!"<<endl;
	return 0;
}