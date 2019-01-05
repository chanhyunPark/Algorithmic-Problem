#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> v[1010];
bool visit[1010][11];
vector<int> tmp;
bool flag = false;
void Dfs(int day, int dduk) 
{
	if (flag)
		return;

	if (day == N + 1)
	{
		int size = tmp.size();
		for (int i = 0; i < size; i++)
			cout << tmp[i] << "\n";

		flag = true;
		return;
	}

	int size = v[day].size();
	for (int i = 0; i < size; i++)
	{
		if (v[day][i] != dduk && !visit[day][v[day][i]])
		{
			visit[day][v[day][i]] = true;
			tmp.push_back(v[day][i]);
			Dfs(day+1, v[day][i]);
			tmp.pop_back();
			visit[day][v[day][i]] = false;
			if (flag)
				return;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int n = 1; n <= N; n++)
	{
		int cnt;
		cin >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			int num;
			cin >> num;
			v[n].push_back(num);
		}
	}

	Dfs(1, 0);

	if (!flag)
		cout << -1 << "\n";
		

	return 0;
}