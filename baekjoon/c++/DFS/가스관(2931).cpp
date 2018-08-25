#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

typedef struct Player
{
	//좌표
	int y;
	int x;
	//방향
	int d;

public:
	Player() {}
	Player(int y, int x, int d) : y(y), x(x), d(d) {}

};

int R, C;
Player moscba, zag;
bool mCheck = false;
char map[30][30];
bool mapVisit[30][30][4];
bool visit[30][30][4]; //방향별 방문처리를 해줘야함
int dir[4][2] = { { -1, 0 },{ 1,0 },{ 0,-1 },{ 0,1 } }; //위,아래,왼쪽, 오른쪽
char tunnelWhat[7] = {'|', '-', '+', '1', '2', '3', '4'};
bool ansFlag = false;
bool tunnel[7][4] = {
	{ true, true, false,false },
{ false, false, true, true },
{ true, true, true, true },
{ false, true, false, true },
{ true, false, false, true },
{ true, false, true, false },
{ false, true, true, false }
};

bool isCheck(int d, int tunnel)
{
	if (d == 1) // 아래
	{
		if (tunnel == 0 || tunnel == 2 || tunnel == 4 || tunnel == 5)
		{
			return true;
		}
	}
	else if (d == 0)
	{
		if (tunnel == 2 || tunnel == 0 || tunnel == 3 || tunnel == 6)
		{
			return true;
		}
	}
	else if (d == 2) //왼쪽
	{
		if (tunnel == 2 || tunnel == 1 || tunnel == 3 || tunnel == 4)
			return true;
	}
	else if (d == 3)
	{
		if (tunnel == 2 || tunnel == 1 || tunnel == 5 || tunnel == 6)
			return true;
	}
	return false;
}

bool update()
{
	memset(visit, false, sizeof(visit));
	Player srt;
	int flag = false;

	for (int i = 0; i < 4; i++)
	{
		int ny = moscba.y + dir[i][0];
		int nx = moscba.x + dir[i][1];

		if (ny >= 0 && nx >= 0 && ny < R && nx < C)
		{
			if (map[ny][nx] == '.' || map[ny][nx] == 'Z')
				continue;
			else
			{
				flag = true;
				srt = Player(ny, nx, i);
				visit[ny][nx][i] = true;
				break;
			}
		}
	}

	bool ans = false;
	if (flag)
	{
		queue<Player> q;
		q.push(srt);
		visit[srt.y][srt.x][srt.d] = true;
		bool stopFlag = false;
		while (!q.empty())
		{
			Player start = q.front();
			q.pop();

			bool af = false;
			if (start.y == zag.y && start.x == zag.x)
			{
				ans = true;
			}

			int ny = start.y + dir[start.d][0];
			int nx = start.x + dir[start.d][1];

			if (!visit[ny][nx][start.d] && tunnel[map[start.y][start.x] - '0'][start.d] && isCheck(start.d, map[ny][nx] - '0'))
			{
				visit[ny][nx][start.d] = true;
				q.push(Player(ny, nx, start.d));
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					ny = start.y + dir[i][0];
					nx = start.x + dir[i][1];

					if (tunnel[map[start.y][start.x] - '0'][i])
					{
						if (ny >= 0 && nx >= 0 && ny < R && nx < C)
						{
							if (map[ny][nx] != '.' && isCheck(i, map[ny][nx] - '0') && !visit[ny][nx][i])
							{
								visit[ny][nx][i] = true;
								q.push(Player(ny, nx, i));
							}
							else if (map[ny][nx] == 'Z')
							{
								visit[ny][nx][i] = true;
								q.push(Player(ny, nx, i));
							}
							else if (map[ny][nx] == '.')
							{
								stopFlag = true;
								break;
							}
						}
						else
						{
							stopFlag = true;
							break;
						}
					}
				}
			}

			if (stopFlag)
			{
				ans = false;
				break;
			}
		}
	}

	return ans;
}

void Dfs(Player player, int cnt, int tun)
{
	if (ansFlag)
		return;

	if (cnt == 1)
	{
		if (update())
		{
			ansFlag = true;
			cout << player.y + 1 << " " << player.x + 1 << " "  << tunnelWhat[tun] << "\n";
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		Player tmp;
		int ny = player.y + dir[i][0];
		int nx = player.x + dir[i][1];

		if (ny >= 0 && nx >= 0 && ny < R && nx < C)
		{
			if (!mapVisit[ny][nx][i])
			{
				mapVisit[ny][nx][i] = true;
				if (player.d == -1) // 시작일땐
				{
					if (map[ny][nx] != '.' && isCheck(i, map[ny][nx] - '0'))
					{
						tmp = Player(ny, nx, i);
						Dfs(tmp, cnt, -1);
					}
					else if (map[ny][nx] == '.' && !mCheck)
					{
						for (int t = 0; t < 7; t++)
						{
							if (isCheck(i, t)) //현재 위치에서 갈 수 있고, 그 방향으로 갈 수 있는 터널인가?
							{
								map[ny][nx] = t + '0';
								tmp = Player(ny, nx, i);
								Dfs(tmp, cnt + 1, t);
								map[ny][nx] = '.';
							}
						}
					}
				}
				else
				{
					if (map[ny][nx] != '.' && isCheck(i, map[ny][nx] - '0'))
					{
						tmp = Player(ny, nx, i);
						Dfs(tmp, cnt, -1);
					}
					else if (map[ny][nx] == '.')
					{
						for (int t = 0; t < 7; t++)
						{
							if (tunnel[map[player.y][player.x] - '0'][i] && isCheck(i, t)) //터널 넣기
							{
								map[ny][nx] = t + '0';
								tmp = Player(ny, nx, i);
								Dfs(tmp, cnt + 1, t);
								map[ny][nx] = '.';
							}
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> R >> C;

	for (int r = 0; r < R; r++)
	{
		string str;
		cin >> str;
		for (int c = 0; c < C; c++)
		{
			map[r][c] = str[c];
			if (map[r][c] == '|')
			{
				map[r][c] = '0';
			}
			else if (map[r][c] == '-')
			{
				map[r][c] = '1';
			}
			else if (map[r][c] == '+')
				map[r][c] = '2';
			else if (map[r][c] >= '1' && map[r][c] <= '4')
			{
				map[r][c] = (map[r][c] - '0') + '2';
			}
			else if (map[r][c] == 'M')
			{
				moscba = Player(r, c, -1);
				
				for (int i = 0; i < 4; i++)
				{
					int ny = r + dir[i][0];
					int nx = c + dir[i][1];

					if (ny >= 0 && nx >= 0 && ny < R && nx < C)
					{
						if (isCheck(i, map[ny][nx] - '0'))
						{
							mCheck = true;
							break;
						}
					}
				}
			
			}
			else if (map[r][c] == 'Z')
			{
				zag = Player(r, c, -1);
			}
		}
	}

	Dfs(moscba, 0, -1);

	return 0;
}