#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N,x;
vector<vector<int>> vt;
int bfs() 
{
	queue < vector<vector<int>>> qu;
	qu.push(vt);
	int ret = 0, c = 0; 
	while (qu.size())
	{
		int qs = qu.size();
		while (qs--)
		{
			vector<vector<int>> v = qu.front();
			vector<vector<int>> visited(N);
			qu.pop();
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					ret = max(ret, v[i][j]);
				}
			}

			for (int i = 0; i < N; i++)
				visited[i].assign(N, 0);

			vector<vector<int>> up = v;
			for (int i = 1; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					int cx = i;
					while (cx - 1 >= 0 && up[cx - 1][j] == 0)
						cx--;
					if (cx - 1 >= 0 && up[cx - 1][j] == up[i][j] && !visited[cx - 1][j])
					{
						up[cx - 1][j] = up[i][j] * 2;
						up[i][j] = 0;
						visited[cx - 1][j] = 1;
					}
					else
						swap(up[cx][j], up[i][j]);
				}
			}

			for (int i = 0; i < N; i++)
				visited[i].assign(N, 0);

			vector<vector<int>> down = v;
			for (int i = N - 2; i >= 0; i--)
			{
				for (int j = 0; j < N; j++)
				{
					int cx = i;

					while (cx + 1 < N && down[cx + 1][j] == 0)
						cx++;

					if (cx + 1 < N && down[cx + 1][j] == down[i][j] && !visited[cx + 1][j])
					{
						down[cx + 1][j] = down[i][j] * 2;
						down[i][j] = 0;
						visited[cx + 1][j] = 1;
					}
					else
						swap(down[cx][j], down[i][j]);
				}
			}
				for (int i = 0; i < N; i++)
					visited[i].assign(N, 0);

				vector<vector<int>> left = v;
				for (int i = 0; i < N; i++)
				{
					for (int j = 1; j < N; j++)
					{
						int cy = j;
						while (cy - 1 >= 0 && left[i][cy - 1] == 0)
							cy--;

						if (cy - 1 >= 0 && left[i][cy - 1] == left[i][j] && !visited[i][cy - 1])
						{
							left[i][cy - 1] = left[i][j] * 2;
							left[i][j] = 0;
							visited[i][cy - 1] = 1;
						}
						else
							swap(left[i][cy], left[i][j]);
					}
				}

				for (int i = 0; i < N; i++)
					visited[i].assign(N, 0);

				vector<vector<int>> right = v;
				for (int i = 0; i < N; i++)
				{
					for (int j = N - 2; j >= 0; j--)
					{
						int cy = j;
						while (cy + 1 < N && right[i][cy + 1] == 0)
							cy++;

						if (cy + 1 < N && right[i][cy + 1] == right[i][j] && !visited[i][cy + 1])
						{
							right[i][cy + 1] = right[i][j] * 2;
							right[i][j] = 0;
							visited[i][cy + 1] = 1;
						}
						else
							swap(right[i][cy], right[i][j]);
					}
				}
			qu.push(up);
			qu.push(down);
			qu.push(left);
			qu.push(right);
		}
		if (c == 5)
			break;
		c++;
	}
	return ret;
}
int main(void)
{
	scanf("%d", &N);
	vt.resize(N);
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < N; m++)
		{
			scanf("%d", &x);
			vt[n].push_back(x);
		}
	}
	printf("%d\n", bfs());
	return 0;
}