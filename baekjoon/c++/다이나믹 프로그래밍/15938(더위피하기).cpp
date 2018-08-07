#include<iostream>
using namespace std;

#define MOD 1000000007

int sX, sY;
int T;
int N;
int eX, eY;
int dp[201][501][501];
int dir[4][2] = { {-1, 0},{1, 0}, {0, -1},{0, 1} };
int main(void)
{
	cin >> sX >> sY;
	cin >> T;
	cin >> eX >> eY;
	cin >> N;

	eX = T + eX - sX;
	eY = T + eY - sY;

	for (int n = 0; n < N; n++) //장애물
	{
		int x, y;
		cin >> x >> y;
		
		if (x > sX + T || x < sX - T || y > sY + T || y < sY - T)
			continue;

		dp[0][T + x - sX][T + y - sY] = -1;
	}

	int subX = T - sX;
	int subY = T - sY;


	//dp 초기화
	for (int i = 0; i <= 2 * T; i++)
	{
		for (int j = 0; j <= 2 * T; j++)
		{
			if (j - subY < -100000 || j - subY > 100000)
				dp[0][i][j] = -1;

			if (i - subX < -100000 || i - subX > 100000)
				dp[0][i][j] = -1;
		}
	}

	if (eX > 2 * T || eX < 0 || eY > 2 * T || eY < 0)
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i <= 2 * T; i++)
	{
		for (int j = 0; j <= 2 * T; j++)
		{
			if (dp[0][i][j] == -1)
			{
				dp[1][i][j] = -1;
				continue;
			}

			if (i == T && j == T)
			{
				for (int d = 0; d < 4; d++)
				{
					int nx = T + dir[d][0];
					int ny = T + dir[d][1];

					if (dp[0][nx][ny] == -1)
						continue;
					dp[1][nx][ny] = 1;
				}
			}
		}
	}

	for (int t = 2; t <= T; t++)
	{
		dp[t][eX][eY] = dp[t - 1][eX][eY];
		for (int i = 0; i <= 2 * T; i++)
		{
			for (int j = 0; j <= 2 * T; j++)
			{
				if (dp[t - 1][i][j] == -1)
				{
					dp[t][i][j] = -1;
					continue; //갈 필요없음
				}
				
				if (i == eX && j == eY)
					continue;

				if (dp[t - 1][i][j] == 0)
					continue;

				for (int d = 0; d < 4; d++)
				{
					int nx = i + dir[d][0];
					int ny = j + dir[d][1];
					
					if (nx < 0 || nx > 2 * T || ny < 0 || ny > 2 * T)
						continue;

					if (dp[t - 1][nx][ny] == -1)
						continue;

					dp[t][nx][ny] += (dp[t - 1][i][j] % MOD);
					dp[t][nx][ny] = dp[t][nx][ny] % MOD;
				}
			}
		}
	}

	cout << dp[T][eX][eY] << '\n';
	return 0;
}