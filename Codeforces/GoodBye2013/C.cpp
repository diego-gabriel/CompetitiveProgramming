#include <iostream>
#include <algorithm>

using namespace std;

struct User
{
	int wanted;
	int received;
	int ID;

	User(){};
};

bool ordByWan(User a, User b)
{
	return a.wanted < b.wanted;
}

bool ordByID(User a, User b)
{
	return a.ID < b.ID;
}

int main()
{
	int n;
	cin>>n;

	User users[n];

	for (int i = 0; i < n; i++)
	{
		users[i].ID = i;
		cin>>users[i].wanted;
	}

	sort(users, users + n, ordByWan);

	int upper = 1;

	for (int i = 0; i < n; i++)
	{
		if (users[i].wanted < upper)
		{
			users[i].received = upper;
			upper++;
		}
		else
		{
			users[i].received = users[i].wanted;
			upper = users[i].wanted + 1;
		}
	}

	sort(users, users + n, ordByID);

	cout<<users[0].received;
	for (int i = 1; i < n; i++)
	{
		cout<<" "<<users[i].received;
	}
	cout<<endl;
}