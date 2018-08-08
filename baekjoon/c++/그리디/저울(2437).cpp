#include<iostream>
#include<vector>
#include<algorithm>

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

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (sum + 1 < v[i])
			break;
		else
			sum += v[i];
	}

	cout << sum + 1 << '\n';
	return 0;
}
