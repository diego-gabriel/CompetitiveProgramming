#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	unsigned int n, l, u;

	while (cin>>n>>l>>u)
	{
		bool bits[100];
		memset(bits, false, sizeof(bits));
		int i = -1;
		unsigned int num = n;

		while (num)
		{
			i++;
			bits[i] = num & 1;
			num = num>>1;
		}

		unsigned int res = 0;
		unsigned int act = 0x80000000;
		for (int c = 31; c >= 0; c--, act /= 2)
		{
			if (bits[c])
			{
				if (res + (act - 1) < l)
					res += act;
			}
			else
			{
				if (res + act <= u)
					res += act;
			}

		}

		cout<<res<<endl;
		// 1100100
	}

	return 0;
}