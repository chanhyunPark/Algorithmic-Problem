#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> v;
	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<int>());
	int ans = v[0];
	int k = 2;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] * k > ans)
		{
			ans = v[i] * k;
		}
		k++;

	}

	cout << ans << '\n';
	return 0;
}
