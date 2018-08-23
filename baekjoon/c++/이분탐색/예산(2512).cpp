#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long M;
vector<int> v;
int sum = 0;
int cnt = 0;
int FindMoney(int idx)
{
	int s = 0;
	if (idx > 0)
		s = v[idx - 1];

	int e = v[idx];
	int mid = 0;
	int maxValue = -1;
	while (s <= e)
	{
		mid = (s + e) / 2;

		if (mid *(N-cnt) + sum <= M)
		{
			maxValue = max(maxValue, mid);
			s = mid + 1;
		}
		else if (mid * (N - cnt) + sum > M)
		{
			e = mid - 1;
		}
	}

	return maxValue;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(false);

	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> M;
	sort(v.begin(), v.end());
	int ans = 0;
	for (int n = 0; n < N; n++)
	{
		if (v[n] * N < M && n == 0)
		{
			sum += v[n];
			cnt++;
			continue;
		}
		else if (sum + v[n] * (N - cnt) < M)
		{
			sum += v[n];
			cnt++;
		}
		else
		{
			cout << FindMoney(n) << '\n';
			return 0;
		}
	}

	cout << v[v.size() - 1] << '\n';
	return 0;
}