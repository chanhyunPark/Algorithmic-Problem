#include<iostream>
#include<string>
#include<queue>

#define WID 0
#define COL 1

using namespace std;
typedef struct loc
{
	pair<int, int> w[3];
	int dir; // 0 - 가로 1 - 세로
}loc;

int N;
char map[52][52];
bool visit[52][52][2];
loc tree;
loc endPoint;
int ans = 0;

int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
int turDirS[6][2] = { { -1,-1 },{ -1,1 },{ 1,-1 },{ 1,1 },{ 0,-1 },{ 0,1 } };
int turDirW[6][2] = { { -1,-1 },{ -1,1 },{ 1,-1 },{ 1,1 },{ -1,0 },{ 1,0 } };

//방향에 따른 나무 변화 0 - 아래, 1 - 위, 2 - 좌 3 - 우 4 - 턴
bool isTurnRange(int y, int x, int d) //세로면 대각선이랑 좌,우 가로면 대각선이랑 상, 하
{
	int ny = 0;
	int nx = 0;
	if (d == COL)
	{
		for (int i = 0; i < 6; i++)
		{
			ny = y + turDirS[i][0];
			nx = x + turDirS[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
			{
				return false;
			}
		}
	}
	else if (d == WID)
	{
		for (int i = 0; i < 6; i++)
		{
			ny = y + turDirW[i][0];
			nx = x + turDirW[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
			{
				return false;
			}
		}
	}
	return true;
}

bool isRange(loc var, int d)
{
	for (int i = 0; i < 3; i++)
	{
		int ny = var.w[i].first + dir[d][0];
		int nx = var.w[i].second + dir[d][1];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
			return false;
	}
	return true;
}

pair<loc, bool> changeDir(loc var, int d)
{
	bool ck = false;
	switch (d)
	{
	case 0:	//아래
		if (isRange(var,d))
		{
			for (int i = 0; i < 3; i++)
			{
				var.w[i].first = var.w[i].first + dir[d][0];
				var.w[i].second = var.w[i].second + dir[d][1];
			}
			ck = true;
		}
		break;
	case 1: //위
		if (isRange(var, d))
		{
			for (int i = 0; i < 3; i++)
			{
				var.w[i].first = var.w[i].first + dir[d][0];
				var.w[i].second = var.w[i].second + dir[d][1];
			}
			ck = true;
		}
		break;
	case 2: //좌
		if (isRange(var, d))
		{
			for (int i = 0; i < 3; i++)
			{
				map[var.w[i].first][var.w[i].second] = '0';
				var.w[i].first = var.w[i].first + dir[d][0];
				var.w[i].second = var.w[i].second + dir[d][1];
				map[var.w[i].first][var.w[i].second] = 'B';
			}
			ck = true;
		}
		break;
	case 3: //우
		if (isRange(var, d))
		{
			for (int i = 0; i < 3; i++)
			{
				var.w[i].first = var.w[i].first + dir[d][0];
				var.w[i].second = var.w[i].second + dir[d][1];
			}
			ck = true;
		}
		break;
	case 4:
		if (isTurnRange(var.w[1].first, var.w[1].second, var.dir))
		{
			if (var.dir == WID) // 가로면
			{
				int tmp1[2] = { var.w[0].first,var.w[0].second }, tmp2[2] = { var.w[2].first,var.w[2].second };
				var.w[0].first = tmp1[0] - 1;
				var.w[0].second = tmp1[1] + 1;
				var.w[2].first = tmp2[0] + 1;
				var.w[2].second = tmp2[1] - 1;
				var.dir = COL;
			}
			else if (var.dir == COL)
			{
				int tmp1[2] = { var.w[0].first,var.w[0].second }, tmp2[2] = { var.w[2].first,var.w[2].second };
				var.w[2].first = tmp1[0] + 1;
				var.w[2].second = tmp1[1] + 1;
				var.w[0].first = tmp2[0] - 1;
				var.w[0].second = tmp2[1] - 1;
				var.dir = WID;
			}
			ck = true;
		}
		break;
	}
	return make_pair(var, ck);
}

bool endCondition(loc var, loc end)
{
	if (var.w[0].first == end.w[0].first && var.w[0].second == end.w[0].second &&
		var.w[1].first == end.w[1].first && var.w[1].second == end.w[1].second
		&& var.w[2].first == end.w[2].first && var.w[2].second == end.w[2].second)
		return true;

	return false;
}

int main(void)
{
	cin >> N;
	int b = 0;
	int e = 0;

	for (int n = 0; n < N; n++)
	{
		cin >> map[n];
		for (int m = 0; m < N; m++)
		{
			if (map[n][m] == 'B')
			{
				map[n][m] = '0';
				tree.w[b] = make_pair(n, m);
				int y = tree.w[b].first - tree.w[b - 1].first;
				int x = tree.w[b].second - tree.w[b - 1].second;

				if (y != 0)
					tree.dir = COL;

				if (x != 0)
					tree.dir = WID;

				b++;
			}
			else if (map[n][m] == 'E')
			{
				endPoint.w[e] = make_pair(n, m);
				int y = endPoint.w[e].first - endPoint.w[e - 1].first;
				int x = endPoint.w[e].second - endPoint.w[e - 1].second;

				if (y != 0)
					endPoint.dir = COL;

				if (x != 0)
					endPoint.dir = WID;
				e++;
			}
		}
	}

	queue<pair<loc, int>> q;

	q.push(make_pair(tree, 0));
	visit[tree.w[1].first][tree.w[1].second][tree.dir] = true;

	while (!q.empty())
	{
		loc t = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (endCondition(t, endPoint))
		{
			ans = cnt;
			break;
		}

		for (int i = 0; i < 5; i++) // 0 - 아래, 1 - 위, 2 - 좌 3 - 우 4 - 턴
		{
			pair<loc, bool> tmp = changeDir(t, i);

			if (!visit[tmp.first.w[1].first][tmp.first.w[1].second][tmp.first.dir] && tmp.second)
			{
				visit[tmp.first.w[1].first][tmp.first.w[1].second][tmp.first.dir] = true;
				q.push(make_pair(tmp.first, cnt + 1));
			}
		}
	}
	cout << ans << endl;
}
