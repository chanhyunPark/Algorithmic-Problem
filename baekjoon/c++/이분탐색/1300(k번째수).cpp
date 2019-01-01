#include<iostream>
#include<algorithm>

using namespace std;

int N, K;
int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> K;


	int left = 1;
	int right = K;
	int ans = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cnt += min(mid / i, N);

			if (cnt > K)
				break;
		}

		if (cnt >= K)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans;

	return 0;
}