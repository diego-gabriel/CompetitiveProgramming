#include <iostream>
#include <set>
#include <map>
#include <cstdio>xx

using namespace std;

int main()
{
	int n;
	bool fst = true;

	while (cin>>n)
	{
		//if (!fst) cout<<endl;

		map<int, int> books;

		int price;

		for (int i = 0; i < n; i++)
		{
			cin>>price;
			books[price]++;
		}

		pair <int, int> res;
		int total, tar;
		cin>>total;

		tar = (total + 1) / 2;

		if (tar * 2 == total && books[tar] >= 2)
		{
			res = make_pair(tar, tar);
		}
		else
		{
			while (!(books[tar] >= 1 && books[total-tar] >= 1)) tar--;
			res = make_pair(tar, total - tar);
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", res.first, res.second);

		fst = false;
	}

	return 0;
}