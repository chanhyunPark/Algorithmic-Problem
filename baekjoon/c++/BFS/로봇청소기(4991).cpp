#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

typedef struct Robot 
{
	int y;
	int x;
	int key;

public:
	Robot() {}
	Robot(int y, int x, int key) : y(y), x(x), key(key) {}

};


int H, W;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int dist[22][22][1300];
int map[22][22];
int dCnt = 1;
vector<pair<pair<int, int>, int>> dV;
int main(void)
{
	while (true)
	{
		cin >> W >> H;

		if (H == 0 && W == 0)
			break;

		dCnt = 1;
		int mask = 0;
		Robot start;
		for (int h = 0; h < H; h++)
		{
			string str;
			cin >> str;
			for (int w = 0; w < W; w++)
			{
				char c = str[w];

				if (c == '.')
					map[h][w] = 0;
				else if (c == 'x')
					map[h][w] = -1;
				else if (c == '*')
				{
					mask |= (1 << (dCnt - 1));
					map[h][w] = dCnt++;
				}
				else if (c == 'o')
				{
					map[h][w] = 0;
					start = Robot(h,w,0);
				}
			}
		}


		memset(dist,0,sizeof(dist));

		queue<Robot> q;
		q.push(start);
		bool flag = false;

		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			int key = q.front().key;
			
			q.pop();

		
			if (key == mask)
			{
				flag = true;
				cout << dist[y][x][key] << endl;
				break;
			}


			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= H || nx >= W)
					continue;

				if (map[ny][nx] == -1)
					continue;


				if (map[ny][nx] == 0 && dist[ny][nx][key] == 0)
				{
					dist[ny][nx][key] = dist[y][x][key] + 1;
					q.push(Robot(ny,nx,key));
				}
				
				
				int tmp = key;
				tmp |= (1 << (map[ny][nx] - 1));
				if (map[ny][nx] >= 1 && dist[ny][nx][tmp] == 0)
				{
					dist[ny][nx][tmp] = dist[y][x][key] + 1;
					q.push(Robot(ny,nx,tmp));
				}
			}
		}

		if (!flag)
			cout << -1 << '\n';
	}

	return 0;
}