#include<iostream>
#include<queue>
using namespace std;

typedef struct tomatoDir {

	int h;
	int y;
	int x;
	int cnt;

public:
	tomatoDir() {}
	tomatoDir(int h, int y, int x,int cnt) : h(h), y(y), x(x), cnt(cnt) {}
};
int M, N, H;
int tomato[100][100][100];
bool visit[100][100][100];
int dir[6][3] = { {1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,-1}, {0,0,1} };
bool flag;
bool toflag;
int cnt;
int main(void)
{
	queue<tomatoDir> q;
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) //층
	{
		for (int n = 0; n < N; n++) // 세로
		{
			for (int m = 0; m < M; m++)  // 가로
			{
				cin >> tomato[h][n][m]; //1은 익은 토마토 0 - 익지 않은 토마토 -1 토마토가 들어가있지 않은 칸
				if (tomato[h][n][m] == 0)
				{
					flag = true;
				}
				else if (tomato[h][n][m] == 1)
				{
					q.push(tomatoDir(h,n,m,0));
				}
			}
		}
	}

	if (!flag)
	{
		cout << "0" << endl;
	}
	else
	{
		while (!q.empty())
		{
			int h = q.front().h;
			int y = q.front().y;
			int x = q.front().x;
			cnt = q.front().cnt;
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int nh = h + dir[i][0];
				int ny = y + dir[i][1];
				int nx = x + dir[i][2];

				if (nh >= 0 && ny >= 0 && nx >= 0 && nh < H && ny < N && nx < M)
				{
					if (tomato[nh][ny][nx] == 0 && !visit[nh][ny][nx])
					{
						tomato[nh][ny][nx] = 1;
						visit[nh][ny][nx] = true;
						q.push(tomatoDir(nh,ny,nx,cnt+1));
					}
				}
			}
		}
	}

	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (tomato[h][n][m] == 0)
				{
					cout << "-1" << endl;
					return 0;
				}
			}
		}
	}

	cout << cnt << endl;

}