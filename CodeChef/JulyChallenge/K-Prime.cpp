#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int esPrimo[100000 + 1];
int res[5][100000 + 1];
void initCriba()
{
    memset(esPrimo, -1, sizeof(esPrimo));

    esPrimo[0] = esPrimo[1] = -1;
	
	res[0][0] = res[0][1] = 0;
	res[1][0] = res[1][1] = 0;
	res[2][0] = res[2][1] = 0;
	res[3][0] = res[3][1] = 0;
	res[4][0] = res[4][1] = 0;
	
    for (int i = 2; i <= 100000; i++)
    {
        if (esPrimo[i]==-1)
        {
			for (int j = i + i; j <= 100000; j += i)
			{ 
				if(esPrimo[j]==-1) esPrimo[j]=0;
					esPrimo[j]++;
			}
			esPrimo[i] = 1;
        }
        int k = esPrimo[i]; 
        
        res[0][i] = res[0][i-1] + (k == 1);
        res[1][i] = res[1][i-1] + (k == 2);
        res[2][i] = res[2][i-1] + (k == 3);
        res[3][i] = res[3][i-1] + (k == 4);
        res[4][i] = res[4][i-1] + (k == 5);
        
    }

}

int main()
{
    int n;
    cin>>n;
    initCriba();
    while (n--)
    {
        int a, b, k;
        cin>>a>>b>>k;
        cout<<res[k-1][b] - res[k-1][a - 1]<<endl;
    }
    return 0;
}
