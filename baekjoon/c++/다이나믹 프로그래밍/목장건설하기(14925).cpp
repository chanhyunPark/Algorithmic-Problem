#include<iostream>
#include<algorithm>
using namespace std;

int M, N;
int map[1010][1010];
int dp[1010][1010];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;

	int cnt = 0;
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			cin >> map[m][n];
			if (map[m][n] == 0)
			{
				dp[m][n] = 1;
				cnt++;
			}
			else
				dp[m][n] = -1;
		}
	}


	int maxValue = 0;

	if (cnt > 0)
		maxValue = 1;

	for (int m = 1; m < M; m++)
	{
		for (int n = 1; n < N; n++)
		{
			int minValue = 987654321;
			if (dp[m][n] != -1 && dp[m - 1][n - 1] != -1 && dp[m][n - 1] != -1 && dp[m - 1][n] != -1)
			{
				minValue = min(minValue, min(dp[m - 1][n], min(dp[m][n - 1], dp[m - 1][n - 1])));
				dp[m][n] = minValue + 1;

				if (maxValue < dp[m][n])
					maxValue = dp[m][n];
			}
			else
				continue;
		}
	}

	cout << maxValue << endl;
	return 0;
}