#include<iostream>
#include<string.h>
using namespace std;
int T;
int M, N, K;
int bacu[51][51] = {0,};
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[51][51];
int cx, cy;
int cnt;
void sol(int x, int y)
{
	for (int d = 0; d < 4; d++) 
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
		{
			if (bacu[ny][nx] == 1 && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				sol(nx, ny);
			}
		}
	}
}
int main(void)
{
	cin >> T;
	int cnt;
	memset(visit, false, sizeof(visit));
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		memset(bacu, 0, sizeof(bacu));
		for (int k = 0; k < K; k++)
		{
			cin >> cx >> cy;
			bacu[cy][cx] = 1;
		}
		cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (bacu[n][m] == 1 && !visit[n][m])
				{
					visit[n][m] = true;
					sol(m, n);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
