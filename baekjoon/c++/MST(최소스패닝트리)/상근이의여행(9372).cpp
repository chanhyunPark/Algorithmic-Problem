#include<iostream>

using namespace std;

int T;
int N, M;
int p[1001];

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return (p[x] = find(p[x]));
}

void disjoin_union(int x, int y)
{
	x = find(x);
	y = find(y);

	p[x] = y;
}

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;

		for (int n = 1; n <= N; n++)
			p[n] = n;

		int cnt = 0;
		for (int m = 0; m < M; m++)
		{
			int x, y;
			cin >> x >> y;

			x = find(x);
			y = find(y);

			if (x != y)
			{
				disjoin_union(x,y);
				cnt += 1;
			}
		}

		cout << cnt << endl;
	}


	return 0;
}