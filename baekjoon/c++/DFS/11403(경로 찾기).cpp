#include<iostream>

using namespace std;

int N;
int map[101][101];
int ans[101][101];
int visit[101];

void dfs(int start)
{

	for (int n = 0; n < N; n++)
	{
		if (map[start][n] == 1 && visit[n] == 0)
		{
			visit[n] = 1;
			dfs(n);
		}
	}

}

int main(void)
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			cin >> map[n][m];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < N; i++)
			visit[i] = 0;

		dfs(i);
		for (int n = 0; n < N; n++)
		{
			ans[i][n] = visit[n];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int n = 0; n < N; n++)
			cout << ans[i][n] << ' ';

		cout << '\n';
	}
}