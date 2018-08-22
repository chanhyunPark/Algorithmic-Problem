#include<iostream>

using namespace std;

int N;
int map[1001];
int dp[1001];
int main(void)
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> map[n];
	}

	dp[0] = 1;
	int max = -1;
	for (int n = 1; n < N; n++)
	{
		dp[n] = 1;
		for (int m = 0; m <= n; m++)
		{
			if (map[n] > map[m] && dp[n] < dp[m] + 1)
			{
				dp[n] = dp[m] + 1;
			}
		}

		if (max < dp[n])
			max = dp[n];
	}

	cout << max << '\n';

	return 0;
}