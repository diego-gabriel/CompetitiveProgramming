#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

int nod[1000000 + 5];
int n[70000];
int res[1000000+5];

void initDiv()
{
	memset(nod, 0, sizeof(nod));

	nod[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		for (int c = i; c <= 1000000; c += i)
		{
			nod[c]++;
		}
}

void init()
{
	n[0] = 1;
	int i = 1;

	while (n[i-1] <= 1000000)
	{
		n[i] = n[i-1] + nod[n[i-1]];
		i++;
	}

	res[0] = 0;
	int nN = 0;
	for (int c = 1; c < 1000000 + 1; c++)
	{
		//cout<<n[nN]<<endl;
		if (n[nN] == c) nN++;
		res[c] = nN;
	}

}

int main()
{
	initDiv();
	init();
	int test = 0;
	int nTest;
	int a, b;
	cin>>nTest;

	while (nTest--)
	{
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", ++test, res[b] - res[a-1]);
	}
	return 0;
}