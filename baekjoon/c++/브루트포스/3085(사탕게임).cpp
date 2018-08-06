#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int N;
char map[51][51];
bool visit[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans = -1;
int candyCnt = 0;
bool flag = false;

int reverseDir(int dir)
{
	int ans = 0;
	switch (dir)
	{
	case 0:
		ans = 1;
		break;
	case 1:
		ans = 0;
		break;
	case 3:
		ans = 2;
		break;
	case 2:
		ans = 3;
		break;	
	}

	return ans;
}

void Dfs(int y, int x, char start, int cnt, int d)
{
	candyCnt = max(candyCnt, cnt);
	int ny = y + dir[d][0];
	int nx = x + dir[d][1];

	if (ny >= 0 && nx >= 0 && ny < N && nx < N)
	{
		if (!visit[ny][nx])
		{
			if (map[ny][nx] == start)
			{
				visit[ny][nx] = true;
				Dfs(ny, nx, start, cnt + 1, d);
			}
			else
			{
				if (!flag)
				{
					flag = true;
					int rDir = reverseDir(d);
					for (int i = 0; i < 4; i++)
					{
						int cy = ny + dir[i][0];
						int cx = nx + dir[i][1];

						if (cy >= 0 && cx >= 0 && cy < N && cx < N && rDir != i)
						{
							if (map[cy][cx] == start)
							{
								swap(map[ny][nx], map[cy][cx]);
								Dfs(ny, nx, start, cnt + 1, d);
								swap(map[cy][cx], map[ny][nx]);
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
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;
		for (int m = 0; m < N; m++)
		{
			map[n][m] = str[m];
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = n + dir[i][0];
				int nx = m + dir[i][1];

				if (ny >= 0 && nx >= 0 && ny < N && nx < N)
				{
					visit[n][m] = true;
					Dfs(n,m,map[n][m], 1, i);
					ans = max(ans, candyCnt);
					candyCnt = 0;
					flag = false;
					visit[n][m] = false;
					memset(visit,false,sizeof(visit));
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
