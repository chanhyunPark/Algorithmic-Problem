#include<iostream>
#include<string>

using namespace std;

typedef struct Robot 
{
	int y;
	int x;
	int d;
public:
	Robot() {}
	Robot(int y, int x, int d) : y(y), x(x), d(d) {}
};

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //북,남,동,서
int M;
int n;

int reverseDir(int dir, int c)
{
	if (c == 1)
	{
		if (dir == 0)
			return 2;
		else if (dir == 1)
			return 3;
		else if (dir == 2)
			return 1;
		else
			return 0;
	}
	else
	{
		if (dir == 0)
			return 3;
		else if (dir == 1)
			return 2;
		else if (dir == 2)
			return 0;
		else if (dir == 3)
			return 1;
	}

}

bool isRange(int y, int x)
{
	if (y < 0 || y > M || x < 0 || x > M)
		return false;

	return true;
}

int main(void)
{
	cin >> M >> n;
	
	Robot robot = Robot(0,0,2);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		string obey;
		int cnt;

		int ny = robot.y;
		int nx = robot.x;
		int d = robot.d;
		cin >> obey >> cnt;

		if (obey == "MOVE")
		{
			ny += dir[d][0] * cnt;
			nx += dir[d][1] * cnt;

			robot = Robot(ny,nx, d);
		}
		else if (obey == "TURN")
		{
			int chDir = reverseDir(d,cnt);
			robot = Robot(ny, nx, chDir);
		}

		if (!isRange(ny, nx))
		{
			flag = true;
		}
	}

	if (!flag)
		cout << robot.x << " " << robot.y << "\n";
	else
		cout << -1 << "\n";

	return 0;
}