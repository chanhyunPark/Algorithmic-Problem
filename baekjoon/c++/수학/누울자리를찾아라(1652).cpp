#include<iostream>
#include<string>
using namespace std;

int N;
char map[101][101];
bool visit[101][101][2]; //가로, 세로

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

	int ansC, ansR;
	ansC = ansR = 0;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			if (!visit[n][m][0] && map[n][m] == '.')
			{
				visit[n][m][0] = true;
				if (n != N)
				{
					int cnt = 1;
					int ny = n + 1;
					while (true)
					{
						if (map[ny][m] == 'X' || visit[ny][m][0] || ny == N)
							break;

						if (map[ny][m] == '.')
						{
							visit[ny][m][0] = true;
							cnt++;
							ny++;
						}
					}
					if (cnt >= 2)
						ansR++;
				}
			}

			if (!visit[n][m][1] && map[n][m] == '.')
			{
				visit[n][m][1] = true;
				if (m != N)
				{
					int cnt = 1;
					int nx = m + 1;
					while (true)
					{
						if (map[n][nx] == 'X' || visit[n][nx][1] || nx == N)
							break;

						if (map[n][nx] == '.')
						{
							visit[n][nx][1] = true;
							cnt++;
							nx++;
						}
					}
					if (cnt >= 2)
						ansC++;
				}
			}
		}
	}

	cout << ansC << " " << ansR << endl;
	
	return 0;
}