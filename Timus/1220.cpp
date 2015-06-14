#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int main()
{
	int startPos[1000];
	int val[100000];
	memset(startPos, 0, sizeof(startPos));
	int n;
	char com[5];
	int p, v;
	
	scanf("%d", &n);
	
	
	while (n--)
	{
		scanf("%s %d", com, &p);
		p--;
		
		if (com[1] == 'U')
		{
			scanf("%d", &v);
			startPos[p]++;
		}
	}
	
	
	for (int i = 1; i < 1000; i++)
	{
		startPos[i] += startPos[i-1];
	}
	
	fseek(stdin, 0, SEEK_SET);
	
	scanf("%d", &n);
	
	while (n--)
	{
		scanf("%s %d", com, &p);
		p--;
		
		if (com[1] == 'U')
		{
			scanf("%d", &v);
			val[startPos[p]] = v;
			startPos[p]--;
		}
		else
		{
			startPos[p]++;
			printf("%d\n", val[startPos[p]]);
		}
	}
	
	return 0;
}
