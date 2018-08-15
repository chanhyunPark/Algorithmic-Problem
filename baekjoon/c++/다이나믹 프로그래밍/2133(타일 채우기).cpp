#include<iostream>

using namespace std;

long long dp[31];
int main(void)
{
	int N;
	
	cin >> N;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= N + 1; i++)
	{
		if (i % 2 == 1)
			continue;

		dp[i] = dp[i - 2] * dp[2];

		for (int j = 0; j <= i - 4; j++)
		{
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[N] << endl;

	return 0;
}