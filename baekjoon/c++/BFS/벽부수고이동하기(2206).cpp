#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct Node
{
	int y;
	int x;
	bool f;

public:
	Node() {}
	Node(int y, int x, int f) : y(y), x(x), f(f) {}

};


int map[1001][1001];
int visit[1001][1001][2];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M;
int main(void)
{
	cin >> N >> M;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		for (int m = 0; m < M; m++)
		{
			map[n][m] = str[m] - '0';
			visit[n][m][0] = 987654321;
			visit[n][m][1] = 987654321;
		}
	}

	queue<Node> q;
	q.push(Node(0,0,false));
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		bool flag = q.front().f;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			if (visit[y][x][0] < visit[y][x][1])
				cout << visit[y][x][0] << endl;
			else
				cout << visit[y][x][1] << endl;

			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (map[ny][nx] == 0)
				{
					if (!flag)
					{
						if (visit[ny][nx][0] >= visit[y][x][0] + 1)
						{
							visit[ny][nx][0] = visit[y][x][0] + 1;
							q.push(Node(ny,nx,flag));
						}
					}
					else
					{
						if (visit[ny][nx][1] >= visit[y][x][1] + 1)
						{
							visit[ny][nx][1] = visit[y][x][1] + 1;
							q.push(Node(ny,nx,flag));
						}
					}
				}

				if (map[ny][nx] == 1 && !flag && visit[ny][nx][1] >= visit[y][x][0] + 1)
				{
					visit[ny][nx][1] = visit[y][x][0] + 1;
					q.push(Node(ny,nx,true));
				}
			}
		}
	}

	cout << "-1" << endl;
	return 0;
}