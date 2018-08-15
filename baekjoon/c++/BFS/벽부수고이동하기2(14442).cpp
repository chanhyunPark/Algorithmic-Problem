#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct Node
{
	int y;
	int x;
	int f;

public:
	Node() {}
	Node(int y, int x, int f) : y(y), x(x), f(f) {}

};


int map[1001][1001];
int visit[1001][1001][15];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int N, M, K;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		for (int m = 0; m < M; m++)
		{
			map[n][m] = str[m] - '0';
			for (int i = 0; i <= 10; i++)
				visit[n][m][i] = 987654321;
		}
	}

	queue<Node> q;
	q.push(Node(0, 0, false));
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int flag = q.front().f;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			int ans = 987654321;
			for (int i = 0; i <= K; i++)
			{
				ans = min(ans,visit[y][x][i]);
			}
			
			cout << ans << "\n";

			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (map[ny][nx] == 0 && flag <= K)
				{
					if (flag == 0)
					{
						if (visit[ny][nx][0] > visit[y][x][0] + 1)
						{
							visit[ny][nx][0] = visit[y][x][0] + 1;
							q.push(Node(ny, nx, flag));
						}
					}
					else if(flag != 0)
					{
						if (visit[ny][nx][flag] > visit[y][x][flag] + 1)
						{
							visit[ny][nx][flag] = visit[y][x][flag] + 1;
							q.push(Node(ny, nx, flag));
						}
					}
				}

				if (map[ny][nx] == 1 && visit[ny][nx][flag + 1] > visit[y][x][flag] + 1)
				{
					visit[ny][nx][flag + 1] = visit[y][x][flag] + 1;
					q.push(Node(ny, nx, flag + 1));
				}
			}
		}
	}

	cout << "-1" << endl;
	return 0;
}