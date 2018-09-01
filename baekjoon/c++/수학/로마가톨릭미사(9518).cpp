#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int R, C;
char map[60][60];
bool visit[60][60];
int dir[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1} };

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
		}
	}

	int cnt = 0;
	vector<pair<int, int>> v;
	int maxvalue = -1;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cnt = 0;
			if (map[r][c] == '.')
			{
				for (int i = 0; i < 8; i++)
				{
					int ny = r + dir[i][0];
					int nx = c + dir[i][1];

					if (ny >= 0 && nx >= 0 && ny < R && nx < C)
					{
						if (map[ny][nx] == 'o')
						{
							cnt++;
						}
					}
				}
			}

			if (maxvalue < cnt)
			{
				maxvalue = cnt;
				v.clear();
				v.push_back({ r,c });
			}
			else if (maxvalue == cnt)
				v.push_back({r,c});
		}
	}

	queue<pair<int, int>> q;
	int ans = -1;
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		map[v[i].first][v[i].second] = 'o';
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				if (map[r][c] == 'o')
				{
					for (int i = 0; i < 8; i++)
					{
						int ny = r + dir[i][0];
						int nx = c + dir[i][1];

						if (ny >= 0 && nx >= 0 && ny < R && nx < C)
						{
							if (map[ny][nx] == 'o')
							{
								cnt++;
							}
						}
					}
				}
			}
		}

		if (ans < (cnt / 2))
			ans = (cnt / 2);

		map[v[i].first][v[i].second] = '.';
	}

	cout << ans << endl;
	return 0;
}