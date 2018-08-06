#include<iostream>

using namespace std;

int R, C;
char map[21][21];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool al[26];
int maxValue = -1;
void Dfs(int y, int x, int cnt)
{
	if (maxValue < cnt)
		maxValue = cnt;

	if (cnt > 26)
		return;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= 0 && nx >= 0 && ny < R && nx < C)
		{
			if (!al[map[ny][nx] - 'A'])
			{
				al[map[ny][nx] - 'A'] = true;
				Dfs(ny,nx,cnt+1);
				al[map[ny][nx] - 'A'] = false;
			}
		}
	}
}
int main(void)
{
	cin >> R >> C;
	for (int r = 0; r < R; r++)
	{
		cin >> map[r];
	}

	al[map[0][0] - 'A'] = true;
	Dfs(0, 0, 1);
		
	cout << maxValue << endl;
	return 0;
}
