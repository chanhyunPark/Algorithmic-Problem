#include<iostream>
#include<algorithm>

using namespace std;

int N;
int num[1001];
int dp[1001];
int minValue = 987654321;
int Dfs(int cnt)
{
	if (cnt == N)
	{
		return 0;
	}

	int &ret = dp[cnt];

	if (ret != -1)
		return ret;

	ret = 987654321;
	if (cnt < N)
	{
		for (int n = 1; n <= N; n++)
		{
			if (cnt + n <= N)
			{
				ret = min(ret, Dfs(cnt + n) + num[n]);
			}
		}
	}

	return ret;
}

int main(void)
{
	cin >> N;

	memset(dp, -1 ,sizeof(dp));
	for (int n = 1; n <= N; n++)
		cin >> num[n];

	cout << Dfs(0) << "\n";

	return 0;
}