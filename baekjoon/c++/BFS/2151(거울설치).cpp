#include<iostream>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct mirror 
{
	int y;
	int x;
	int type;
	int d;
	int cnt;
	public:
		mirror() {}
		mirror(int y, int x, int d, int cnt, int type) 
			: y(y), x(x),d(d), cnt(cnt), type(type) {}
};

int N; // N은 50이하
char map[60][60];
int visit[100][60][60];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
int mDir[3][5][2] = 
{
	{},
	{{0,0}, {0,1},{0,-1},{1,0},{-1,0}},
	{{0,0}, {0,-1},{0,1},{-1,0},{1,-0}}
};
int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int a = 0; a < 60; a++)
				visit[i][j][a] = 987654321;
		}
	}


	cin >> N;
	int doorCnt = 2;
	mirror doorS, doorE;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		for (int m = 0; m < N; m++)
		{
			map[n][m] = str[m];
			if (map[n][m] == '#' && doorCnt == 2)
			{
				doorS = mirror(n, m, 0, 0, 0); //시작
				doorCnt--;
			}
			else if (map[n][m] == '#' && doorCnt == 1)
			{
				doorE = mirror(n, m, 0, 0, 0); //끝
			}
		}
	}
	queue<mirror> q;
	q.push(doorS);
	int ans = 987654321;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt; //거울의 갯수
		int d = q.front().d; //방향
		int type = q.front().type; //0은 문 1 - 통과 방 2 - 거울
		q.pop();

		if (y == doorE.y && x == doorE.x)
		{
			ans = min(ans,cnt);
		}

		if (type == 0)
		{
			for (int i = 1; i < 5; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (ny >= 0 && nx >= 0 && ny < N && nx < N)
				{
					if (map[ny][nx] == '.')
						q.push(mirror(ny, nx, i, cnt, 1));
					else if (map[ny][nx] == '!')
						q.push(mirror(ny, nx, i, cnt, 2));
					else if (map[ny][nx] == '#')
						q.push(mirror(ny, nx, i, cnt, -1));
				}
			}
		}

		if (type == 1)
		{
			int ny = y + dir[d][0];
			int nx = x + dir[d][1];

			if (ny >= 0 && nx >= 0 && ny < N && nx < N && visit[d][ny][nx] > cnt)
			{
				visit[d][ny][nx] = cnt;
				if (map[ny][nx] == '.')
					q.push(mirror(ny, nx, d, cnt, 1));
				else if (map[ny][nx] == '!')
					q.push(mirror(ny, nx, d, cnt, 2));
				else if (map[ny][nx] == '#')
					q.push(mirror(ny, nx, d, cnt, -1));
			}
		}

		if (type == 2)
		{
			int ny = y + dir[d][0];
			int nx = x + dir[d][1];

			if (ny >= 0 && nx >= 0 && ny < N && nx < N && visit[d][ny][nx] > cnt)
			{
				visit[d][ny][nx] = cnt;
				if (map[ny][nx] == '.')
					q.push(mirror(ny, nx, d, cnt, 1));
				else if (map[ny][nx] == '!')
					q.push(mirror(ny, nx, d, cnt, 2));
				else if (map[ny][nx] == '#')
					q.push(mirror(ny, nx, d, cnt, -1));
			}


			for (int i = 1; i < 3; i++)
			{
				ny = y + mDir[i][d][0];
				nx = x + mDir[i][d][1];

				int tmp;
				if (d == 1)
				{
					if (i == 1)
						tmp = 4;
					else
						tmp = 3;
				}
				else if (d == 2)
				{
					if (i == 1)
						tmp = 3;
					else
						tmp = 4;
				}
				else if (d == 3)
				{
					if (i == 1)
						tmp = 2;
					else
						tmp = 1;
				}
				else
				{
					if (i == 1)
						tmp = 1;
					else
						tmp = 2;
				}

				if (ny >= 0 && nx >= 0 && ny < N && nx < N && visit[tmp][ny][nx] > cnt+1)
				{
					visit[tmp][ny][nx] = cnt+1;
					if (map[ny][nx] == '.')
						q.push(mirror(ny, nx, tmp, cnt + 1, 1));
					else if (map[ny][nx] == '!')
						q.push(mirror(ny, nx, tmp, cnt + 1, 2));
					else if (map[ny][nx] == '#')
						q.push(mirror(ny, nx, tmp, cnt + 1, -1));
				}
			}
		}
	}

	if (ans == 987654321)
		cout << 0 << '\n';
	else
		cout << ans << '\n';
}