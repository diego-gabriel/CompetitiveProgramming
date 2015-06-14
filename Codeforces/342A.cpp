#include <iostream>

using namespace std;

int main()
{
	int n1, n2, n3, n4, n6;

	n1 = n2 = n3 = n4 = n6 = 0;

	int n, v;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>v;
		if (v == 5 || v == 7)
		{
			cout<<-1<<endl;
			return 0;
		}

		if (v == 1)
			n1++;
		if (v == 2)
			n2++;
		if (v == 3)
			n3++;
		if (v == 4)
			n4++;
		if (v == 6)
			n6++;
	}
	if (n1 == n/3 && (n2 + n3) == n/3 && (n4 + n6) == n/3 && n3 <= n6)
	{
		while (n1--)
		{
			cout<<"1 ";
			if (n2)
			{
				n2--;
				cout<<"2 ";
				if (n4)
				{
					n4--;
					cout<<4<<endl;
				}
				else
				if (n6)
				{
					n6--;
					cout<<6<<endl;
				}
			}
			else
			if (n3)
			{
				n3--;
				n6--;
				cout<<"3 6"<<endl;
			}
		}
	}
	else cout<<-1<<endl;
	return 0;
}