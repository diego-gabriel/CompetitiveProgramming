#include <iostream>

using namespace std;

int main()
{
	int t[7];
	int c1, c2;

	while (cin>>t[1]>>t[2]>>t[3]>>t[4]>>t[5]>>t[6] && (t[1] || t[2] || t[3] || t[4] || t[5] || t[6]))
	{
		int res = 0;
		c1 = c2 = 0;

		res += t[6];
		res += t[5];
		c1 += (11*t[5]);
		res += t[4];

		c2 += (5*t[4]);
		res += ((t[3] + 3) / 4);

		switch (t[3] % 4)
		{
			case 1: {
				c2 += 5;
				c1 += 7;
			} break;

			case 2: {
				c2 += 3;
				c1 += 6;
			} break;

			case 3: {
				c2 += 1;
				c1 += 5;
			} break;
		}

		c2 -= t[2];
		if(c2 >= 0)
		{
			c1 += (c2*4);
		}
		else
		{
			t[2] = -c2;

			res += ((t[2] + 8) / 9);

			c1 += ((9 - (t[2] % 9)) * 4);
		}

		c1 -= t[1];

		if (c1 < 0)
		{
			t[1] = -c1;
			res += ((t[1] + 35) / 36);
		}

		cout<<res<<endl;
	}
	

	return 0;
}