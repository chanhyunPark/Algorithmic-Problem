#include<iostream>
#include<vector>
#include<set>
#include<string.h>
using namespace std;

int T;
int N, M;
bool visit[201];
bool v[201][201];
int cnt = 0;
void Dfs(int cur, int index, int iceCnt)
{
	if (index > N + 1)
		return;
	
	if (iceCnt > 3)
		return;

	if(iceCnt == 3)
	{
		cnt++;
		return;
	}

	for (int i = index; i <= N; i++)
	{
		if (!v[cur][i] && cur != i && cur < i && !v[index-1][i])
		{
			Dfs(cur, i + 1, iceCnt + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	memset(visit, false, sizeof(visit));
	cnt = 0;

	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b;
		v[a][b] = true;
		v[b][a] = true;
	}

	for (int n = 1; n <= N; n++)
	{
		Dfs(n, 1, 1);
	}

	cout << cnt << "\n";

	return 0;
}