#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct Signal
{
	int y;
	int x;
	int dir;
	int cnt;

public:
	Signal() {}
	Signal(int y, int x, int dir, int cnt) : y(y), x(x), dir(dir), cnt(cnt) {}

};

int N, M;
int PR, PC;
int dir[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } }; //위, 오른쪽, 아래, 왼쪽
int maxValue = -1;
char ans;
char map[1000][1000];
int visit[502][502];

int getVertical(int dir, char planet)
{
	if (planet == '\\')
	{
		switch (dir)
		{
		case 0:
			return 3;
		case 1:
			return 2;
		case 2:
			return 1;
		case 3:
			return 0;
		}
	}
	else if (planet == '/')
	{
		switch (dir)
		{
		case 0:
			return 1; //오른쪽
		case 1:
			return 0; //up
		case 2:
			return 3; //left
		case 3:
			return 2; //down
		}
	}
}

char getDirChar(int dir) 
{
	switch (dir)
	{
	case 0:
		return 'U';
	case 1:
		return 'R';
	case 2:
		return 'D';
	case 3:
		return 'L';
	}
}

bool isRange(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;

	return true;
}

void Print(int y, int x) 
{
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (n == y && m == x)
				cout << "S";
			else
				cout << map[n][m];
		}
		cout << '\n';
	}

	cout << '\n';
}

int main(void)
{
	cin >> N >> M;

	for (int n = 0; n < N; n++)
	{
		cin >> map[n];
	}

	cin >> PR >> PC; //시작 위치

	PR--;
	PC--;

	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		Signal signal;
		memset(visit,0,sizeof(visit));

		signal = Signal(PR, PC, i, cnt + 1);
		while (true)
		{
			int d = signal.dir;
			int signalCnt = signal.cnt;
			int ny = signal.y + dir[d][0];
			int nx = signal.x + dir[d][1];

			if (!isRange(ny, nx))
			{
				break;
			}

			if (visit[ny][nx] == 2)
			{
				flag = true;
				break;
			}

			if (visit[ny][nx] <= 1)
			{
				visit[ny][nx] += 1;
				if (map[ny][nx] == 'C')
				{
					break;
				}
				else if (map[ny][nx] == '.')
				{
					signal = Signal(ny, nx, d, signalCnt + 1);
				}
				else if (map[ny][nx] == '\\')
				{
					d = getVertical(d, '\\');
					signal = Signal(ny, nx, d, signalCnt + 1);
				}
				else if (map[ny][nx] == '/')
				{
					d = getVertical(d, '/');
					signal = Signal(ny, nx, d, signalCnt + 1);
				}
			}
		}

		if (flag)
		{
			ans = getDirChar(i);
			break;
		}

		if (maxValue < signal.cnt)
		{
			ans = getDirChar(i);
			maxValue = signal.cnt;
		}
	}
	cout << ans << '\n';
	if (!flag)
		cout << maxValue << '\n';
	else
		cout << "Voyager\n";
	return 0;
}