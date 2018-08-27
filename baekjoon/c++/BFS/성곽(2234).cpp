#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef struct Room 
{
	bool d[4]; //남, 동, 북, 서
public:
	Room() {}
};

typedef struct Node 
{
	char y;
	char x;
	bool flag;
public:
	Node() {}
	Node(char y, char x, bool flag) : y(y), x(x), flag(flag) {}
};

int N, M;
Room map[51][51];
int visit[51][51];
int visit2[51][51];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0} , {0, -1} };
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			int num;
			cin >> num;
			int bit = 8;
			for (int i = 0; i <= 3; i++)
			{
				if (num >= bit)
				{
					map[m][n].d[i] = true;
					num -= bit;
					bit /= 2;
				}
				else
				{
					map[m][n].d[i] = false;
					bit /= 2;
				}
			}
		}
	}

	int roomCnt = 0;
	int maxRoom = -1;
	vector<int> roomSizes;
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			int roomSize = 0;
			if (!visit[m][n])
			{
				roomCnt++;
				visit[m][n] = roomCnt;
				queue<Node> q;
				q.push(Node(m, n, false));
				while (!q.empty())
				{
					int y = q.front().y;
					int x = q.front().x;
					bool flag = false;

					q.pop();

					roomSize++;

					for (int i = 0; i < 4; i++)
					{
						int ny = y + dir[i][0];
						int nx = x + dir[i][1];

						if (ny >= 0 && nx >= 0 && ny < M && nx < N)
						{
							if (visit[ny][nx] == 0)
							{
								if (!map[y][x].d[i])
								{
									visit[ny][nx] = roomCnt;
									q.push(Node(ny, nx, false));
								}
							}
						}
					}
				}
				roomSizes.push_back(roomSize);
				maxRoom = max(maxRoom, roomSize);
			}
		}
	}

	int tmp = 1;
	int topRoom = -1;
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			int tmpRoomSize = 0;
			if (visit[m][n] == tmp)
			{
				visit2[m][n] = true;
				queue<Node> q;
				q.push(Node(m,n,false));
				while (!q.empty())
				{
					char y = q.front().y;
					char x = q.front().x;
					bool flag = q.front().flag;
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = y + dir[i][0];
						int nx = x + dir[i][1];

						if (ny >= 0 && nx >= 0 && ny < M && nx < N)
						{
							if (visit[ny][nx] == tmp && !visit2[ny][nx])
							{
								visit2[ny][nx] = true;
								q.push(Node(ny, nx, false));
							}
							else if(visit[ny][nx] != tmp)
							{
								topRoom = max(topRoom, roomSizes[tmp-1] + roomSizes[visit[ny][nx] - 1]);
							}
						}
					}
				}
				tmp++;
			}
		}
	}

	cout << roomCnt << "\n";
	cout << maxRoom << "\n";
	cout << topRoom << "\n";

	return 0;
}