#include<iostream>

using namespace std;

int M, N;
int map[1000][1000];
int dp[1000][1000];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int Dfs(int y, int x) 
{
	if (y == M - 1 && x == N - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N)
			continue;

		if(map[y][x] > map[ny][nx])
			ret += Dfs(ny,nx);

	}
	
	return ret;
}


int main(void)
{
	cin >> M >> N;

	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			dp[m][n] = -1;
			cin >> map[m][n];
		}
	}

	cout << Dfs(0, 0) << '\n';

	return 0;
}