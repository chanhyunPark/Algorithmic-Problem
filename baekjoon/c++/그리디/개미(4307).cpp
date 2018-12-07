#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int L, N;
vector<int> v;
int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> L >> N; //자, 개미 갯수

		for (int n = 0; n < N; n++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		int minValue = 0;
		int maxValue = 0;

		//0으로 수렴하거나 끝으로 수렴하거나

		int size = v.size();
		int tmp = 0;
		int tmpM = 0;
		for (int i = 0; i < size; i++)
		{
			int z = v[i];
			int t = L - v[i];
			tmp = z < t ? z : t;
			tmpM = z < t ? t : z;
			minValue = minValue < tmp ? tmp : minValue;
			maxValue = maxValue < tmpM ? tmpM : maxValue;
		}

		cout << minValue << " " << maxValue << "\n";
		v.clear();

	}

	return 0;
}