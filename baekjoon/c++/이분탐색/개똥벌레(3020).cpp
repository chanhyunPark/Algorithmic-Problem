#include<iostream>
#include<algorithm>

using namespace std;

int N, H;
int up[500002];
int down[500002];
int upMax;
int downMax;

int totaldown[500002];
int totalup[500002];
int total[500002];
int main(void)
{
	cin >> N >> H;

	for (int n = 0; n < (N / 2); n++)
	{
		int u, d;
		cin >> d >> u;

		up[u]++;
		down[d]++;

		if (upMax < u)
			upMax = u;

		if (downMax < d)
			downMax = d;
	}

	for (int i = downMax; i >= 1; i--)
		totaldown[i] = down[i] + totaldown[i + 1];

	for (int i = upMax; i >= 1; i--)
		totalup[i] = up[i] + totalup[i + 1];

	int min = 987654321;
	int cnt = 1;
	for (int i = 1; i <= H; i++)
	{
		total[i] = totaldown[i] + totalup[H - i + 1];

		if (total[i] == min)
			cnt++;

		if (total[i] < min)
		{
			cnt = 1;
			min = total[i];
		}
	}

	cout << min << " " << cnt << "\n";

	return 0;
}