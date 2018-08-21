#include<iostream>

using namespace std;

int map[101][101];
long long dp[101][101];
const int dir[2][2] = { {1,0},{0,1} };
int N; //4 <= N <= 100

long long Dfs(int y, int x) 
{
	if (y == N - 1 && x == N - 1)
		return 1;
	
	long long &ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < 2; i++)
	{
		int ny = y + dir[i][0] * map[y][x];
		int nx = x + dir[i][1] * map[y][x];

		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
		{
			ret += Dfs(ny, nx);
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
			cin >> map[n][m]; //각 칸만큼 갈 수 있다.
			dp[n][m] = -1;
		}
	}

	cout << Dfs(0, 0) << '\n';

	return 0;
}