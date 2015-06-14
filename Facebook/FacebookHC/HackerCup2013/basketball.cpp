#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Player
{
	int sp;
	int height;
	string name;
	int timePlayed;
	int draft;

	Player()
	{
		timePlayed = 0;
		draft = 0;
		read();
	}

	void read()
	{
		cin>>name>>sp>>height;
	}

	void print()
	{
		cout<<"name: "<<name<<endl;
		cout<<"shot percentage: "<<sp<<endl;
		cout<<"height: "<<height<<endl;
	}
};

bool ordPlayer(Player a, Player b)
{
	bool res;

	if (a.sp == b.sp)
		res = a.height > b.height;
	else
		res = a.sp > b.sp;

	return res;
}

bool ordOnPlay (Player a, Player b)
{
	bool res;

	if (a.timePlayed == b.timePlayed)
		res = a.draft > b.draft;
	else
		res = a.timePlayed > b.timePlayed;

	return res;
}

bool ordOnBank (Player a, Player b)
{
	bool res;

	if (a.timePlayed == b.timePlayed)
		res = a.draft < b.draft;
	else
		res = a.timePlayed < b.timePlayed;

	return res;
}


struct Team
{
	vector <Player> playing;
	vector <Player> bank;
	int nP;

	Team()
	{}

	Team(vector <Player> players, int i, int p)
	{
		nP = p;
		while (p--)
		{
			playing.push_back(players[i]);
			i += 2;
		}

		while (i < players.size())
		{
			bank.push_back(players[i]);
			i += 2;
		}
	}

	void oneMinute()
	{
		if (!bank.empty())
		{
			for (int i = 0; i < nP; i++)
			{
				playing[i].timePlayed++;
			}

			sort(playing.begin(), playing.end(), ordOnPlay);

			bank.push_back(playing[0]);

			sort(bank.begin(), bank.end(), ordOnBank);

			playing[0] = bank.at(0);

			bank.erase(bank.begin());
		}
	}

	void drop(vector <string> &v)
	{
		for (int i = 0; i < nP; i++)
		{
			v.push_back(playing[i].name);
		}
	}

};

int main()
{
	int nTest;
	cin>>nTest;

	for (int test = 1; test <= nTest; test++)
	{
		int n, m, p;
		cin>>n>>m>>p;

		vector <Player> dudes;

		for (int i = 0; i < n; i++)
			dudes.push_back(Player());

		sort(dudes.begin(), dudes.end(), ordPlayer);

		for (int i = 1; i <= n; i++)
			dudes[i-1].draft = i;

		Team team1, team2;
		team1 = Team(dudes, 0, p);
		team2 = Team(dudes, 1, p);

		for (int i = 0; i < m; i++)
		{
			team1.oneMinute();
			team2.oneMinute();
		}

		vector <string> res;

		team1.drop(res);
		team2.drop(res);

		sort(res.begin(), res.end());

		cout<<"Case #"<<test<<":";

		for(int i = 0; i < res.size(); i++)
			cout<<" "<<res[i];
		cout<<endl;
	}
	return 0;
}