#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int N;
int map[1005][1005];
int dp[1005][1005][4];
int dir[2][2] = { {1,0},{0,1} };

int Dfs(int y, int x, int nxt) 
{
	if (y > N || x > N || x < 0 || y < 0)
		return 0;

	int &ret = dp[y][x][nxt+1];
	
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i < 2; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
		{
			if (map[ny][nx] == (nxt + 1) % 3)
				ret = max(ret, Dfs(ny, nx, ((nxt + 1) % 3)) + 1);
			ret = max(ret, Dfs(ny,nx, nxt));
		}
	}
	return ret;
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
	
	memset(dp, -1, sizeof(dp));

	if (map[0][0] == 0)
		cout << Dfs(0, 0, 0) + 1 << endl;
	else
		cout << Dfs(0, 0, -1) << endl;

	return 0;
}