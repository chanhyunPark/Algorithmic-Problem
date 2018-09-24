#include<iostream>
#include<queue>
#include<string>

using namespace std;

int N, k;
int map[2][100050];
bool visit[2][100050];
int main(void)
{
	string str;

	cin >> N >> k;

	cin >> str;
	for (int n = 0; n < N; n++)
		map[0][n] = str[n] - '0';

	cin >> str;
	for (int n = 0; n < N; n++)
		map[1][n] = str[n] - '0';

	queue<pair<int, int>> q;

	q.push(make_pair(0,0)); // 왼쪽 첫번째
	bool flag = false;
	for (int t = 1; t <= N+1; t++)
	{
		visit[0][t - 1] = true;
		visit[1][t - 1] = true;

		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			int lr = q.front().first;
			int jump = q.front().second;
			q.pop();

			if (jump >= N)
			{
				flag = true;
				break;
			}

			if (map[lr][jump + 1] == 1 && !visit[lr][jump + 1])
			{
				visit[lr][jump + 1] = true;
				q.push(make_pair(lr, jump + 1));
			}
			else
			{
				if (jump + 1 >= N)
					q.push(make_pair(lr,jump + 1));
			}

			if (jump > 0 && map[lr][jump - 1] == 1 && !visit[lr][jump - 1])
			{
				visit[lr][jump - 1] = true;
				q.push(make_pair(lr, jump - 1));
			}

			if (lr == 0)
			{
				if (map[lr + 1][jump + k] == 1) 
				{
					if (!visit[lr + 1][jump + k])
					{
						visit[lr + 1][jump + k] = true;
						q.push(make_pair(lr + 1, jump + k));
					}
				}

				if (jump + k >= N)
					q.push(make_pair(lr + 1, jump + k));
			}

			if (lr == 1)
			{
				if (map[lr - 1][jump + k] == 1)
				{
					if (!visit[lr - 1][jump + k])
					{
						q.push(make_pair(lr - 1, jump + k));
						visit[lr - 1][jump + k] = true;
					}
				}

				if (jump + k >= N)
					q.push(make_pair(lr - 1, jump + k));
			}
		}

		if (flag)
			break;	
	}

	if (flag)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}