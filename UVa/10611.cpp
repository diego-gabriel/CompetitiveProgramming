#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n;

	while (cin>>n)
	{
		set <int> chimp;
		set <int> :: iterator it;

		int c;

		for (int i = 0; i < n; i++)
		{
			cin>>c;
			chimp.insert(c);
		}

		int nq, s;
		cin>>nq;
		bool isIn;

		for (int i = 0; i < nq; i++)
		{
			cin>>s;
			it = chimp.find(s);

			isIn = it != chimp.end();

			if (!isIn)
			{
				chimp.insert(s);
				it = chimp.find(s);
			}

			if (it == chimp.begin())
				cout<<"X";
			else
			{
				it--;
				cout<<*it;
				it++;
			}
			it++;

			if (it == chimp.end())
				cout<<" X"<<endl;
			else
				cout<<" "<<*it<<endl;

			if (!isIn)
			{
				chimp.erase(s);
			}
		}
	}

	return 0;
}