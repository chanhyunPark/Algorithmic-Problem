#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[21];
bool visit[2000001];

void Dfs(int idx, int sum) 
{
	if (idx == N)
	{
		visit[sum] = true;
		return;
	}

	Dfs(idx + 1, sum + num[idx]);
	Dfs(idx + 1, sum);
}

int main(void)
{
	cin >> N;

	int ans = 0;
	for (int n = 0; n < N; n++)
	{
		cin >> num[n];
		ans += num[n];
	}

	sort(num, num + N);

	Dfs(0,0);

	for (int n = 1; n <= ans; n++)
	{
		if (!visit[n])
		{
			cout << n << '\n';
			return 0;
		}
	}

    
    cout << ans + 1 << '\n';
	return 0;
}