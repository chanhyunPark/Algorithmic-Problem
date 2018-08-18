#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct robot 
{
	int y;
	int x;
	int dir;
	int cnt;
	robot(int y, int x, int dir, int cnt) : y(y), x(x), dir(dir), cnt(cnt) {};
	robot() {};

}robot;

int M, N; //세로 M, 가로 N
int map[101][101];
bool visit[101][101][4];
// 동쪽 - 1, 서쪽 - 2, 남쪽 - 3, 북쪽 - 4
int dxy[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1 ,0} };
queue<robot> q;

void func(queue<robot> &q, int y, int x, int dir, int cnt) 
{
	robot res;
	for(int k = 1; k <= 3; k++)
	{
		int ny = y + dxy[dir][0] * k;
		int nx = x + dxy[dir][1] * k;

		if (ny < 1 || nx < 1 || ny > M || nx > N)
			break;

		if (map[ny][nx] == 1)
			break;

		if (visit[ny][nx][dir])
			continue;
	
		visit[ny][nx][dir] = true;
		q.push(robot(ny, nx, dir, cnt+1));
	}
}

int turnLeft(int d)
{
	switch (d)
	{
		case 1:
			return 4;
		case 2:
			return 3;
		case 3:
			return 1;
		case 4:
			return 2;
	}

	return -1;
}

int turnRight(int d)
{
	switch (d)
	{
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 2;
	case 4:
		return 1;
	}
	return -1;
}
int main(void)
{
	int minvalue = 1000000;
	cin >> M >> N;

	for (int m = 1; m <= M; m++)
	{
		for (int n = 1; n <= N; n++)
		{
			cin >> map[m][n]; // 0은 궤도가 깔려 있어 로봇이 갈 수 있는 지점 1은 궤도가 없어 로봇이 갈 수 없는 지점
		}
	}
	int starty = 0, startx = 0, startdir = 0; // 시작 좌표, 시작 방향
	int endy = 0, endx = 0, enddir = 0; // 도착 좌표, 도착 방향
	cin >> starty >> startx >> startdir;
	cin >> endy >> endx >> enddir;
	// GO k 현재 향하고 있는 방향으로 k칸 만큼 움직임
	// turn dir dir left, right 왼쪽 혹인 오른쪽 90 회전
	//최소 명령 횟수
	q.push(robot(starty, startx, startdir,0));
	visit[starty][startx][startdir] = true;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();

		if (y == endy && x == endx && dir == enddir)
		{
			minvalue = min(minvalue, cnt);
			continue;
		}
		func(q,y,x,dir,cnt);
		int d = turnLeft(dir);
		if (!visit[y][x][d])
		{
			visit[y][x][d] = true;
			q.push(robot(y,x,d,cnt+1));
		}
		d = turnRight(dir);
		if (!visit[y][x][d])
		{
			visit[y][x][d] = true;
			q.push(robot(y,x,d,cnt+1));
		}
	}
	
	cout << minvalue << '\n';
	return 0;
}
//9%