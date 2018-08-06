#include<iostream>
#include<algorithm>

using namespace std;

int N;
int map[21][21];
bool visit[21];
int ans = 987654321;
void update() 
{
	int sum1 = 0, sum2 = 0;
	for (int n = 1; n <= N; n++)
	{
		if (visit[n])
		{
			for (int m = n + 1; m <= N; m++)
			{
				if (visit[m])
				{
					sum1 += map[n][m];
					sum1 += map[m][n];
				}
			}
		}
	}

	for (int n = 1; n <= N; n++)
	{
		if (!visit[n])
		{
			for (int m = n + 1; m <= N; m++)
			{
				if (!visit[m])
				{
					sum2 += map[n][m];
					sum2 += map[m][n];
				}
			}
		}
	}
	ans = min(ans, abs(sum1-sum2));
}

void Dfs(int start, int len)
{
	if (start > N)
		return;

	if (len == (N / 2))
	{
		update();
	}

	for (int i = start; i <= start + (N/2) - 1; i++)
	{
		visit[i] = true;
		Dfs(i+1, len + 1);
		visit[i] = false;
	}
}
int main(void)
{
	cin >> N;
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= N; m++)
		{
			cin >> map[n][m];
		}
	}
	Dfs(1,0);
	cout << ans << endl;
	return 0;
}	